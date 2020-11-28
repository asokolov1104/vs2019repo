//
#include <iostream>
#include <vector>
//
auto main() -> int {

	//	sizeof empty vector
	{
		std::vector<int> v;
		printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));
	}

	//	sizeof vector with one element
	{
		std::vector<int> v = { 1 };
		printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));
	}

	//	sizeof vector with two elements
	{
		std::vector<int> v = { 1, 3 };
		printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));
	}

	//	sizeof vector with three elements
	{
		std::vector<int> v = { 1, 3, 5 };
		printf("sizeof vector with %d elements: %d\n", v.size(), sizeof(v));
	}


	//
	{
		std::vector<int> v = { 1,2,3,1,2,3,1,2,3 };
		for (auto& el : v)
			printf("%3d", el);
		std::cout << std::endl;

		auto iter = std::remove(v.begin(), v.end(), 2);
		for (auto& el : v)
			printf("%3d", el);
		std::cout << std::endl;

		v.erase(std::remove(v.begin(), v.end(), 2), v.end());
		for (auto& el : v)
			printf("%3d", el);
		std::cout << std::endl;
	}

	return 0;
}