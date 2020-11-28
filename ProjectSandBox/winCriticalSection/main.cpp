//
#include <windows.h>
#include <iostream>

//	КОНСТАНТЫ
const INT	_NUM_THREADS = 3;
const INT	_NUM_LOOPs = 1000;
const LONG	_LOOP_DELAY = 1L;
//const BOOL	_SYNCH_TRHEADs = TRUE;
const BOOL	_SYNCH_TRHEADs = FALSE;
//const BOOL	_USE_SPIN_COUNT = TRUE;
const BOOL	_USE_SPIN_COUNT = FALSE;

//	ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
long g_x1 = 0;
long g_x2 = 0;

//	КРИТИЧЕСКИЕ СЕКЦИИ
CRITICAL_SECTION cs_1;
CRITICAL_SECTION cs_2;


//	ФУНКЦИИ ПОТОКОВ
DWORD WINAPI ThreadFunc1(PVOID pvParam)
{
	//
	DWORD	dwResult = 0;
	int		lCounter = 0;

	//	Основной цикл потока
	while (lCounter < _NUM_LOOPs)
	{
		if (_SYNCH_TRHEADs)
		{
			EnterCriticalSection(&cs_1);
			++g_x1;
			LeaveCriticalSection(&cs_1);
		}
		else
			++g_x1;

		++lCounter;
		Sleep(_LOOP_DELAY);
	}

	// ..
	return dwResult;
}

DWORD WINAPI ThreadFunc12(PVOID pvParam)
{
	//
	DWORD	dwResult = 0;
	int		lCounter = 0;

	//	Основной цикл потока
	while (lCounter < _NUM_LOOPs)
	{
		if (_SYNCH_TRHEADs)
		{
			EnterCriticalSection(&cs_1);
			++g_x1;
			LeaveCriticalSection(&cs_1);

			EnterCriticalSection(&cs_2);
			++g_x2;
			LeaveCriticalSection(&cs_2);
		}
		else
		{
			++g_x1;
			++g_x2;
		}


		++lCounter;
		Sleep(_LOOP_DELAY);
	}

	// ..
	return dwResult;
}

DWORD WINAPI ThreadFunc2(PVOID pvParam)
{
	//
	DWORD	dwResult = 0;
	int		lCounter = 0;

	//	Основной цикл потока
	while (lCounter < _NUM_LOOPs)
	{
		if (_SYNCH_TRHEADs)
		{
			EnterCriticalSection(&cs_2);
			++g_x2;
			LeaveCriticalSection(&cs_2);
		}
		else
			++g_x2;

		++lCounter;
		Sleep(_LOOP_DELAY);
	}

	// ..
	return dwResult;
}


//	ГЛАВНАЯ ФУНКЦИЯ
int main()
{
	//	Initialize a critical section object ..
	if (_USE_SPIN_COUNT)
		InitializeCriticalSectionAndSpinCount(&cs_1, 4000);
	else
		InitializeCriticalSection(&cs_1);

	if (_USE_SPIN_COUNT)
		InitializeCriticalSectionAndSpinCount(&cs_2, 4000);
	else
		InitializeCriticalSection(&cs_2);
	
	//	Local variables ..

	//	Thread creating ..
	DWORD dwThreadID[_NUM_THREADS];
	HANDLE hThread[_NUM_THREADS];
	hThread[0] = CreateThread(NULL, 0, ThreadFunc1, NULL, 0, &dwThreadID[0]);
	hThread[1] = CreateThread(NULL, 0, ThreadFunc12, NULL, 0, &dwThreadID[1]);
	hThread[2] = CreateThread(NULL, 0, ThreadFunc2, NULL, 0, &dwThreadID[2]);

	//	Thread is working ..
	std::cout << "Waiting thread's.. " << std::endl;
	WaitForMultipleObjects(_NUM_THREADS, hThread, TRUE, INFINITE);

	//	Result of multithreading ..
	std::cout << "g_x1 = " << g_x1 << std::endl;
	std::cout << "g_x2 = " << g_x2 << std::endl;
	std::cin.get();

	//	Releases all resources ..
	for (int i = 0; i < _NUM_THREADS; ++i)
		CloseHandle(hThread[i]);
	DeleteCriticalSection(&cs_2);
	DeleteCriticalSection(&cs_1);

	//
	return 0;
}
