//
#include <windows.h>
#include <iostream>

//	Раздел описания констант
const int _NUM_THREADS = 10;

//	Раздел описания переменных
struct TThreadParam
{
	int iCounter;
};


//	Функции потоков
DWORD WINAPI ThreadFunc(PVOID pvParam)
{
	DWORD dwResult = 0;

	////	!- Локальная копия структуры - при выходе из потока все данные пропадут..
	//TThreadParam mParam = *((TThreadParam*)pvParam);
	//	.. поэтому далее работаем через указатель на структуру
	TThreadParam *pParam = (TThreadParam*)pvParam;

	//	Основной цикл потока
	while (pParam->iCounter < 50)
	{
		//	Suspends the execution of the current thread
		Sleep(100L);
		++pParam->iCounter;
	}

	// ..
	return dwResult;
}

//
int main(int argc, char* argv)
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
	for (int i = 0; i < _NUM_THREADS; ++i)
		std::cout << "Counter " << i << " = "<< l_threadParam[i].iCounter << std::endl;
	std::cin.get();

	//
	return 0;
}
