//
#include <iostream>

//
enum _CAR_STATE
{
	_CAR_TOP = 0,
	_CAR_RIGHT,
	_CAR_BOTTOM,
	_CAR_LEFT	
};

//
char getCarPos(const _CAR_STATE carState)
{
	char cResult = 0;
	switch (carState)
	{
	case _CAR_TOP:
		cResult = '^'; break;
	case _CAR_LEFT:
		cResult = '<'; break;
	case _CAR_BOTTOM:
		cResult = 0x1F; break;
	case _CAR_RIGHT:
		cResult = '>'; break;
	default:
		break;
	}
	return cResult;
}

//
_CAR_STATE RotareLeft(_CAR_STATE carState)
{
	_CAR_STATE result;
	if (carState == _CAR_TOP)
		result = _CAR_LEFT;
	else
		result = (_CAR_STATE)(carState-1);
	
	return result;
}

//
_CAR_STATE RotareRight(_CAR_STATE carState)
{
	_CAR_STATE result;
	if (carState == _CAR_LEFT)
		result = _CAR_TOP;
	else
		result = (_CAR_STATE)(carState + 1);

	return result;
}

//
int main(int argc, char **argv)
{
	_CAR_STATE iCareState = _CAR_TOP;

	std::cout << getCarPos(iCareState) << std::endl;

	char cCommand;
	do
	{
		std::cin >> cCommand;

		switch (cCommand)
		{
		case'L':
		{
			iCareState = RotareLeft(iCareState);
			std::cout << getCarPos(iCareState) << std::endl;
		} break;
		case'R':
		{
			iCareState = RotareRight(iCareState);
			std::cout << getCarPos(iCareState) << std::endl;
		} break;
		case'B':
		{
			std::cout << getCarPos(iCareState) << "Beep" << std::endl;
		} break;
		default:
			break;
		}
	} while (cCommand != 'E');

	return 0;
}
