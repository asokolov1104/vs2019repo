//
#include<iostream>
//
class CBase
{
public:
	CBase()
	{
	}
	~CBase()
	{
	}
	virtual void Func()
	{
		std::cout << "class Base :: Calling virtual function"<<std::endl;
	}
};

class CDerived : public CBase
{
public:
	CDerived()
	{
	}
	~CDerived()
	{
	}
	virtual void Func()
	{
		std::cout << "class Direved :: Calling virtual function" << std::endl;
	}
};

//
int main(int argc, char **argv)
{
	if (false)
	{
		CBase m_base;
		m_base.Func();

		CDerived m_der;
		m_der.Func();
	}
	else if (true)
	{
		CDerived m_der;
		CBase *p_base = &m_der;
		p_base->Func();
	}
	else
	{
	}

	
	getchar();
	return 0;
}