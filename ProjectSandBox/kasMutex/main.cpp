
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <fstream>

#define STRICT
#include <atlbase.h>
#include <process.h>


using namespace std;

class RecursiveMutex
{
	RecursiveMutex& operator=(const RecursiveMutex&);
	RecursiveMutex(const RecursiveMutex&);
public:
	RecursiveMutex()
	{
		::InitializeCriticalSection(&m_oRM);
	};

	~RecursiveMutex()
	{
		::DeleteCriticalSection(&m_oRM);
	};

	void Enter()
	{
		::EnterCriticalSection(&m_oRM);
	};

	void Leave()
	{
		::LeaveCriticalSection(&m_oRM);
	};

protected:
	CRITICAL_SECTION m_oRM;
};

class AutoRecursiveMutex
{
	AutoRecursiveMutex& operator=(const AutoRecursiveMutex&);
	AutoRecursiveMutex(const AutoRecursiveMutex&);
public:
	AutoRecursiveMutex(RecursiveMutex* pCs)
		: m_pCs(pCs)
	{
		m_pCs->Enter();
	};
	~AutoRecursiveMutex()
	{
		m_pCs->Leave();
	};
protected:
	RecursiveMutex* m_pCs;
};

int main(int argc, char **argv)
{
	RecursiveMutex m_RM;
	AutoRecursiveMutex m_ARM ( &m_RM);
	getchar();
	return 0;
}
