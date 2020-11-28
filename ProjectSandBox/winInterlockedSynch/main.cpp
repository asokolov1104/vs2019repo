//
#include <windows.h>
#include <iostream>

//	йнмярюмрш
const int	_NUM_THREADS = 20;
const BOOL	_SYNCH_TRHEADs = FALSE;

//	ярпсйрспш
struct TThreadParam
{
	int iCounter;
};

//	цкнаюкэмше оепелеммше
long g_x = 0;


//	тсмйжхх онрнйнб
DWORD WINAPI ThreadFunc(PVOID pvParam)
{
	//
	TThreadParam *pParam = (TThreadParam*)pvParam;

	//
	DWORD	dwResult = 0;
	int		lCounter = 0;

	//	нЯМНБМНИ ЖХЙК ОНРНЙЮ
	while (lCounter < 50)
	{
		//	Suspends the execution of the current thread
		if (_SYNCH_TRHEADs)
			InterlockedExchangeAdd(&g_x, 1);
		else
			++g_x;

		++lCounter;
		Sleep(1);
	}

	// ..
	return dwResult;
}

//	цкюбмюъ тсмйжхъ
int main()
{
	//	Local variables
	TThreadParam l_threadParam[_NUM_THREADS] = { 0 };

	//	Thread creating ..
	DWORD dwThreadID[_NUM_THREADS];
	HANDLE hThread[_NUM_THREADS];
	for (int i = 0; i < _NUM_THREADS; ++i)
		hThread[i] = CreateThread(NULL, 0, ThreadFunc, (PVOID)&l_threadParam[i], 0, &dwThreadID[i]);

	//.. Thread is working
	std::cout << "Waiting single object.. " << std::endl;
	//WaitForSingleObject(hThread, INFINITE);
	WaitForMultipleObjects(_NUM_THREADS, hThread, TRUE, INFINITE);

	//	Result of multithreading
	std::cout << "g_x = " << g_x << std::endl;
	std::cin.get();

	//
	return 0;
}
