//
#include <iostream>
//
int main()
{
	class Base
	{
		virtual void method() { std::cout << "called from Based" << std::endl;  }
	public:
		virtual ~Base() { method(); }
		void baseMethod() { method();  }
	};

	class A : public Base
	{
		void method() { std::cout << "called from A \n" << std::endl;  }
	public:
		~A() { method();  }
	};

	Base* pBase = new A;
	pBase->baseMethod();
	delete pBase;
	return 0;
}