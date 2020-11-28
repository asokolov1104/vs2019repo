//
#include <windows.h>
#include <iostream>

//	������ �������� ��������
const int _NUM_THREADS = 10;

//	������ �������� ����������
struct TThreadParam
{
	int iCounter;
};


//	������� �������
DWORD WINAPI ThreadFunc(PVOID pvParam)
{
	DWORD dwResult = 0;

	////	!- ��������� ����� ��������� - ��� ������ �� ������ ��� ������ ��������..
	//TThreadParam mParam = *((TThreadParam*)pvParam);
	//	.. ������� ����� �������� ����� ��������� �� ���������
	TThreadParam *pParam = (TThreadParam*)pvParam;

	//	�������� ���� ������
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
