#include <iostream>

int main()
{

    std::cout << "\t Study case 1\n";
    class Base
    {
    public:
        virtual ~Base()
        {
            std::cout << "calling ~Base()\n";
        }
    };

 
    class Derived : public Base
    {
    public:
        //virtual ~Derived()      
        ~Derived()
        {
            std::cout << "calling ~Derived()\n";
        }
    };


    Base *Object = new Derived;
    delete Object;

    std::cout << "\t Study case 2\n";

    class BaseErr
    {
    public:
        ~BaseErr()      //  without virtual ~DirevedErr() won't be called
        {               //  AND also leads to ..
            std::cout << "calling ~BaseErr()\n";
        }
    };

    class DerivedErr : public BaseErr
    {
    public:
        ~DerivedErr()   //  .. runtime exception (ntdll) when adding virtual keyword here
        {
            std::cout << "calling ~DerivedErr()\n";
        }
    };

    BaseErr* ObjectErr = new DerivedErr;
    delete ObjectErr;

    std::cout << "\t Study case 3\n";

    DerivedErr* DerivedObj = new DerivedErr;
    delete DerivedObj;

    std::cout << "\t Study case 4\n";
    //  Пример показывает, что достаточно определить виртуальным деструктор базового класса
    //      чтобы вызывались деструкторы порожденных классов
    class Derived2 : public Derived
    {
    public:
        ~Derived2()
        {
            std::cout << "calling ~Derived2()\n";
        }
    };

    Base *pBase = new Derived2;
    delete pBase;
}