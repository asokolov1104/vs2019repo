//
#include <iostream>
#include <memory>

using namespace std;

class Int
{
public:
	Int(int i)
	{
		x = i;
		cout << "Constructing " << (void*)this << " Value: " << x << endl;
	};
	~Int()
	{
		cout << "Destructing " << (void*)this << " Value: " << x << endl;
	};

	int x;
};

class App
{
public:
	App(): m_pi(NULL)
	{
		cout << "App::Contructor " << (void*)this << endl;
		Start();
	}

	~App()
	{
		cout << "App::Destructor " << (void*)this << endl;
		Destroy();
	}
	
	void Start()
	{
		cout << "App::Start() " << (void*)this << endl;
		m_pi.reset(new Int(11));
	}

protected:
	void Destroy()
	{
		cout << "App::Destroy " << (void*)this << endl;
		m_pi.reset();
	}

	auto_ptr<Int> m_pi;

};

int main()
{
	{
		auto_ptr<Int> pi(new Int(5));	//	���������� ����� ��� pi
		pi.reset(new Int(6));			//	����� �������� � pi
		Int* pi2 = pi.get();			//	����� � pi2 ���������� ��� � pi
		Int* pi3 = pi.release();		//	pi3 ����������� ����� pi, � pi � ���� ������� �������� NULL..
		if (pi2 == pi3)					//	.. ������ ������ pi2 � pi3 ����������.. ���������� � ����
			cout << "pi2 == pi3" << endl;
		//delete pi3;	// �� ����� �������� pi2 ��� pi3 - ��� ����� ��������� �� ��� �� ������� ������
		delete pi2;

		getchar();
	}

	{
		App m_app;
	}

	getchar();

	return 0;
}