// basic_ofstream_class.cpp
#include <fstream>

using namespace std;

class App
{
public:
	App(): m_wofs(L"wofstream.log")
	{}

	virtual void LogLine(const wchar_t* wcOut)
	{
		m_wofs << wcOut << endl;
	}

protected:
	wofstream m_wofs;
};

int main(int argc, char **argv)
{
	wofstream ofs("wofstream.txt");
	if (!ofs.bad())
	{
		ofs << "Writing to a basic_ofstream object..." << endl;
		ofs.close();
	}
	//getchar();

	App m_app;
	m_app.LogLine(L"Logging to a basic_ofstream object...");
}
