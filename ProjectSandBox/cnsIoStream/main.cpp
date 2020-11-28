//
#include <iostream>
#include <string>

//
using namespace std;

//	ГЛАВНАЯ ФУНКЦИЯ
int main()
{
	string word;
	int count = 0;
	
	try
	{
		while (cin >> word)
			cout << "Прочитано слов: " << ++count << endl;
	}
	catch (exception& e)
	{
		int i = 0;
	}

	//	Выход из программы по "CTRL + C"
	//	Иногда вываливается - Exception thrown at 0x77026DA7 (kernel32.dll) in cnsIoStream.exe: 0x40010005: Control-C.
	return 0;
}