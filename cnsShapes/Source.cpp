//
#include <iostream>

class CBaseShape
{
private:

public:
	CBaseShape()
	{}

	virtual ~CBaseShape()
	{}

	virtual void draw() = 0;
	//{
	//	std::cout << "draw Base" << std::endl;
	//}
};

class CCircleShape : public CBaseShape
{
protected:
	int x, y;	//	Coord. center of circle
	int r;		//	Radius of circle
public:
	//	Constructor without arguments
	CCircleShape() :
		x(0), y(0), r(0)
	{}

	//	Constructor with arguments
	CCircleShape(int x_, int y_, int r_) :
		x(x_), y(y_), r(r_)
	{}

	~CCircleShape()
	{}

	void draw()
	{
		std::cout << "draw Circle" << std::endl;
	}
};

class CTriangleShape : public CBaseShape
{
protected:
	int x, y;	//	Top corner coord.
	int h;		//	Triangle height 

public:
	//	Constructor without arguments
	CTriangleShape():
		x(0), y(0), h(0)
	{}

	//	Constructor with arguments
	CTriangleShape(int x_, int y_, int h_) :
		x(x_), y(y_), h(h_)
	{}

	~CTriangleShape()
	{}

	void draw()
	{
		std::cout << "draw Triangle" << std::endl;
	}
};

class CSquareShape : public CBaseShape
{
protected:
	int x, y;	//	Top left corner coord.
	int h;		//	square height 

public:
	//	Constructor without arguments
	CSquareShape() :
		x(0), y(0), h(0)
	{}

	//	Constructor with arguments
	CSquareShape(int x_, int y_, int h_) :
		x(x_), y(y_), h(h_)
	{}

	~CSquareShape()
	{}

	void draw()
	{
		std::cout << "draw Square" << std::endl;
	}
};

auto main() -> int
{
	CBaseShape *ptrShapes[3];

	ptrShapes[0] = new CCircleShape(10, 10, 10);
	ptrShapes[1] = new CTriangleShape(20, 20, 20);
	ptrShapes[2] = new CSquareShape(30, 30, 30);

	for (int j = 0; j < 3; ++j)
		ptrShapes[j]->draw();

	for (int j = 0; j < 3; ++j)
		delete ptrShapes[j];

	return 0;
}