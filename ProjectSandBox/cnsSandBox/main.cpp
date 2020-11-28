//

#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

#define STRICT
#include <atlbase.h>
#include <process.h>


//! OsError class 
class OsError
{
public:
	//! Constructs the exception and stores a copy of the szwText inside
	OsError(const wchar_t* szwText)
		: m_wstrText(szwText)
	{
		;
	};

	// returns the error text
	const wchar_t* what() const throw()
	{
		return m_wstrText.c_str();
	};
protected:
	const std::wstring m_wstrText;
};

//! throws an Exception exception based on GetlastError if bResult is zero
void Check_GLE(BOOL bResult, const char* file, int line)
{
	USES_CONVERSION;
	if (!bResult)
	{
		std::wclog << L"An error " << ::GetLastError() << L" occured" << std::endl;
		std::wostringstream os;
		os << L"A Win32 error " << ::GetLastError() << L" occurred at " << (const wchar_t*)A2CW(file) << L"@" << line;
		throw OsError(os.str().c_str());
	};
};

//! check last error and throws an Exception exception if res is zero
#define TSTTASK29_CHK_GLE(res)   Check_GLE((res), __FILE__, __LINE__)


//! Abstract output class 
class ILogger
{
public:
	virtual void LogLine(const wchar_t* szwOut) = 0;
};


//! Abstract control class 
class IDpcCall
{
public:
	virtual void DoCall() = 0;
};


template <class T>
class DpcCallImplT
{
	DpcCallImplT& operator=(const DpcCallImplT&);
	DpcCallImplT(const DpcCallImplT&);
public:
	DpcCallImplT(IDpcCall* pControl)
		: m_hThread(NULL)
		, m_pControl(pControl)
	{
		Create();
	};

	~DpcCallImplT()
	{
		Destroy();
	};

private:
	void Create()
	{
		unsigned uId = 0;
		m_hThread = (HANDLE)::_beginthreadex(
			NULL, 0, &DpcCallImplT::thread_proc,
			(void*)this, 0, &uId);
		//TSTTASK29_CHK_ERRNO(!!m_hThread);
	};

	void Destroy()
	{
		if (m_hThread)
		{
			TSTTASK29_CHK_GLE(::WaitForSingleObject(m_hThread, INFINITE) != WAIT_FAILED);
			TSTTASK29_CHK_GLE(::CloseHandle(m_hThread));
			m_hThread = NULL;
		};
	};

	static unsigned __stdcall thread_proc(void * p)
	{
		try
		{
			DpcCallImplT* pThis = (DpcCallImplT*)p;
			//static_cast<T*>(pThis)->Call();
			T* pMyptr = static_cast<T*>(pThis);
			pMyptr->Call();
			if (pThis->m_pControl)
				pThis->m_pControl->DoCall();
		}
		catch (const OsError& excpt)
		{
			std::wcerr << excpt.what();
		};
		return 0;
	};
private:
	HANDLE          m_hThread;
	IDpcCall*    m_pControl;
};

class DpcCall_1
	: public DpcCallImplT<DpcCall_1>
{
public:
	DpcCall_1(ILogger* pOutput, IDpcCall* pControl)
		: DpcCallImplT<DpcCall_1>(pControl)
	{
		m_pOutput = pOutput;
	};

	~DpcCall_1()
	{
		m_pOutput = NULL;
	};

	virtual void Call()
	{
		for (size_t i = 0; i < 100u; ++i)
		{
			std::wostringstream os;
			os << L"Test1 #" << (i + 1);
			m_pOutput->LogLine(os.str().c_str());
		};
	};
protected:
	ILogger*     m_pOutput;
};

class ApplicationImpl
	: public ILogger
	, public IDpcCall
{
public:
	ApplicationImpl()
		: m_pAction1(NULL)
//		, m_pAction2(NULL)
		, m_osOutput(L"result.log")
	{
		Start();
	};

	~ApplicationImpl()
	{
		Destroy();
	};

	void Start()
	{
		//AutoRecursiveMutex arm(&m_oRM);
		m_pAction1.reset(new DpcCall_1(this, this));
		//m_pAction2.reset(new DpcCall_0(this, this));
	};

protected:
	void Destroy()
	{
		//AutoRecursiveMutex arm(&m_oRM);
		m_pAction1.reset();
		//m_pAction2.reset();
	};

	//ILogger
	virtual void LogLine(const wchar_t* szwOut)
	{
		//AutoRecursiveMutex arm(&m_oRM);
		m_osOutput << szwOut << std::endl;
	};

	//IDpcCall
	virtual void DoCall()
	{
		;
	};

protected:
	//RecursiveMutex              m_oRM;          // protects class variables
	std::auto_ptr<DpcCall_1>  m_pAction1;
	//std::auto_ptr<DpcCall_0> m_pAction2;
	std::wofstream              m_osOutput;
};

class CBaseClass
{
public:
	CBaseClass()
	{
		std::cout << "Constructing BaseClass" << std::endl;
		Create();
	}
	~CBaseClass()
	{
		std::cout << "Destructing BaseClass" << std::endl;
	}

private:
	void Create()
	{
		std::cout << "Call Base Create" << std::endl;
	}
};

class CDerivedClass : public CBaseClass
{
public:
	CDerivedClass()
	{
		std::cout << "Constructing DerivedClass" << std::endl;
		Create();
	}
	~CDerivedClass()
	{
		std::cout << "Destructing DerivedClass" << std::endl;
	}

private:
	void Create()
	{
		std::cout << "Call Derived Create" << std::endl;
	}
};

//
int main(int argc, char **argv)
{
	if(true)
	{
		ApplicationImpl oApp;
	}
	else if(false)
	{
		CDerivedClass mDer;
	}
	else
	{
		DpcCallImplT<DpcCall_1> *pImpl = new DpcCallImplT<DpcCall_1>(NULL);
		DpcCallImplT<DpcCall_1> *pThis = pImpl;
		static_cast<DpcCall_1*>(pThis)->Call();
		delete pImpl;
	}
	getchar();
	return 0;
}