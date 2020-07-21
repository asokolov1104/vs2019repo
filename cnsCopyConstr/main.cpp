#include "iostream"

int main()
{
	class CFloat
	{
	private:
		float fValue;
	public:
		CFloat()
		{
			fValue = 0.0f;
		}
		CFloat(float fInit)
		{
			fValue = fInit;
		}
		void display()
		{
			std::cout << "fValue = " << fValue << "\n";
		}
		CFloat operator = (CFloat& NewValue)
		{
			//	�������� ������������ �������� ����� ���� - �� �� �����������
			//	�������� NewValue ���������� �� ������ ������ ���:
			//	1. �� ��������� ����� ������� (� ������� �������� �� ��������)
			//	2. ������� ����������� ������ (������ ����� ���� �������)
			//	3. �� ������������ ��� �����-� �������
			//	4. �� ���������� ������ ���������� ��������� ��������
			fValue = NewValue.fValue;
			std::cout << "oveloaded  =operator in work \n";
			//	���������� ��������� �� ��������:
			//	1. ������� ��������� ������ CFloat
			//	2. �������������� ������ ��� ������ �����������
			//	������������ ������ - ����� NewValue
			return CFloat(fValue);	//	���������� ����� CFloat
			//return CFloat();	//	��� ���� ��������, ����� ��� fValue = NewValue.fValue
		}
	};

	CFloat f1(6.28f);	//	���������� ������ f1
	f1.display();
	CFloat f2(f1);		//	������������� ������������ (������� 1)
						//	����������� ����������� ����������� �� ���������, �������
						//	1. ������� ������
						//	2. ����������� �������� ����
	f2.display();
	CFloat f3 = f2;		//	������������� ������������ (������� 2)
	f3.display();
	CFloat f4;
	f4 = f3;			//	��������� ������������
	f4.display();

	//	-------------------------------------------------------------------------------------

	class CDecimal
	{
	private:
		int iDecimal;
	public:
		CDecimal()
		{
			iDecimal = 0;
		}

		CDecimal(int iInit)
		{
			iDecimal = iInit;
		}

		CDecimal(CDecimal& Init)
		{
			std::cout << "Copy Contructor in Work\n";
			iDecimal = Init.iDecimal + 1;
		}

		void Display()
		{
			std::cout << "Decimal Value = " << iDecimal << "\n";
		}

		void operator = (CDecimal& NewValue)
		{
			std::cout << "Overloaded =operator in work\n";
			iDecimal = NewValue.iDecimal;
		}
	};

	CDecimal d1(42);
	d1.Display();
	CDecimal d2(d1);
	d2.Display();
	CDecimal d3;
	d3 = d2;
	d3.Display();

	return 0;
}