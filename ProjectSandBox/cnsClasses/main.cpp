//
class CBase
{
protected:
	int		iVar;
	float	fVar;

public:
	CBase() : iVar(-1), fVar(-1.F)
	{}
	CBase(int i, float f) : iVar(i), fVar(f)
	{}

};

class CDerived : public CBase
{
protected:
	double dVar;

public:
	CDerived(): CBase(), dVar(-1.0)
	{}

	CDerived(int i, float f, double d): CBase(i, f), dVar(d)
	{}
};
//
int main(int argc, char **argv)
{
	if (false)
	{
		CBase		m_base;
		CDerived	m_der(0, 3.14F, 5.25);

		m_base = m_der;
		//m_der = m_base;	// binary '=': no operator found which takes a right-hand operand of type 'CBase' (or there is no acceptable conversion)
		// note: could be 'CDerived &CDerived::operator =(CDerived &&)'
		// note: or       'CDerived &CDerived::operator =(const CDerived &)'
		// note: while trying to match the argument list '(CDerived, CBase)'
		//m_der = static_cast<CDerived>(m_base);	// 'static_cast': cannot convert from 'CBase' to 'CDerived'
		// note: No constructor could take the source type, or constructor overload resolution was ambiguous
		CDerived *pm_der = static_cast<CDerived*>(&m_base);	// С объектом производного класса можно обращаться как с объектом базового класса
															// ТОЛЬКО при обращении к нему при помощи УКАЗАТЕЛЕЙ и ССЫЛОК
		CBase *pm_base = &m_der;

		int iPause = 0;
	}
	else if (false)
	{
		CBase		*p_base = new CBase(-5, 32.4f);
		CDerived	*p_der = new CDerived(0, 3.14F, 5.25);

		CBase *pb = p_der;
		//CDerived *pd = p_base;	// cannot convert from 'CBase *' to 'CDerived *'
		// note: Cast from base to derived requires dynamic_cast or static_cast
		CDerived *pd = static_cast<CDerived*>(p_base);

		int iPause = 0;

		delete p_der;
		delete p_base;
	}
	else if (true)
	{
		CDerived	m_der(0, 3.14F, 5.25);
		CBase		m_base = m_der;		//	СРЕЗКА, оператор копирующего присваивания НЕ определен в классе => генерируется компилятором

		int iPause = 0;
	}


	return 0;
}