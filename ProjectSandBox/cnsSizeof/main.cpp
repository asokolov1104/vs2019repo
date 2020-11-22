//
#include <iostream>
#include <vector>
#include <deque>
#include <list>
//
auto main() -> int {

	//	sizeof vector's
	{
		std::vector<int> v;
		printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));

		for (int i = 1; i < 6; ++i) {
			v.push_back(i);
			printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));
		}
	}

	//	sizeof deque's
	{
		std::deque<int> v;
		printf("sizeof deque with %d elements: %d\n", v.size(), sizeof(v));

		for (int i = 1; i < 10; ++i) {
			v.push_back(i);
			printf("sizeof deque with %d elements: %d\n", v.size(), sizeof(v));
		}
	}

	//	sizeof list's
	{
		std::list<int> v;
		printf("sizeof list with %d elements: %d\n", v.size(), sizeof(v));

		for (int i = 1; i < 6; ++i) {
			v.push_back(i);
			printf("sizeof list with %d elements: %d\n", v.size(), sizeof(v));
		}
	}

	return 0;
}