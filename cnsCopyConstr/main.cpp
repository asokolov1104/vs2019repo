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
			//	ОПЕРАТОР ПРИСВАИВАНИЯ УНИКАЛЕН СРЕДИ ВСЕХ - ОН НЕ НАСЛЕДУЕТСЯ
			//	Аргумент NewValue передается по ссылке потому что:
			//	1. Не создается копия объекта (в отличии передачи по значению)
			//	2. Поэтому экономиться память (объект может быть большим)
			//	3. Не генерируются еще какие-н объекты
			//	4. Не завышается оценка количества созданных объектов
			fValue = NewValue.fValue;
			std::cout << "oveloaded  =operator in work \n";
			//	Возвращаем результат по значению:
			//	1. Создаем временный объект CFloat
			//	2. Инициализируем объект при помощи конструктра
			//	Возвращаемый объект - копия NewValue
			return CFloat(fValue);	//	Возвращает копию CFloat
			//return CFloat();	//	Так тоже работает, ВАЖНО что fValue = NewValue.fValue
		}
	};

	CFloat f1(6.28f);	//	Определяем объект f1
	f1.display();
	CFloat f2(f1);		//	Инициализация копированием (вариант 1)
						//	Запускается конструктор копирования по умолчанию, который
						//	1. создает объект
						//	2. поэлементно копирует поля
	f2.display();
	CFloat f3 = f2;		//	Инициализация копированием (вариант 2)
	f3.display();
	CFloat f4;
	f4 = f3;			//	Выражения присваивания
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