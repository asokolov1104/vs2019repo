//
#include <iostream>
#include <string>

//
using namespace std;

//	������� �������
int main()
{
	string word;
	int count = 0;
	
	try
	{
		while (cin >> word)
			cout << "��������� ����: " << ++count << endl;
	}
	catch (exception& e)
	{
		int i = 0;
	}

	//	����� �� ��������� �� "CTRL + C"
	//	������ ������������ - Exception thrown at 0x77026DA7 (kernel32.dll) in cnsIoStream.exe: 0x40010005: Control-C.
	return 0;
}