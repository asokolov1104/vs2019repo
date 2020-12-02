//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
//
struct Ttask {
	int* c = 0;//int* c;

	Ttask() {
		std::cout << "cstr dflt" << std::endl;
		c = new int[10];
	}

	//	without const lead to compile error - why ? Ttask(Ttask& rh) {
	Ttask(const Ttask &rh) {
		std::cout << "cstr asgn" << std::endl;
		c = new int[10];
		memcpy(c, rh.c, 10 * sizeof(int));
	}

	Ttask& operator = (const Ttask& rh) {
		std::cout << "oper asgn" << std::endl;
		if (c != 0) {
			delete[] c;
		}
		c = new int[10];
		memcpy(c, rh.c, 10 * sizeof(int));
		return (*this);
	}

	~Ttask() {
		std::cout << "dstr dstr" << std::endl;
		delete[] c;//delete c;
		c = 0;
	}
};
void print_vector(std::vector<int> & v) {
	std::cout << "vect size/caps: " << v.size() << "/" << v.capacity() << " : { ";
	for (auto& el : v)
		std::cout << el << " ";
	std::cout << "}" << std::endl;

}
//
template<class T, class S>
void print_map(std::map<T, S>& m) {
	std::cout << "map size/maxs/empt: " << m.size() << "/" << m.max_size() << "/" << m.empty() << std::endl;
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << "map[" << it->first << "]=" << it->second << std::endl;
	}
}
//
auto main() -> int {

	int iCase = 2;
	switch (iCase) {
	case 0: {
		std::vector<Ttask> v;
		Ttask T;
		v.push_back(T);
	} break;
	case 1: {
		Ttask t1;
		Ttask t2 = t1;
	} break;
	case 2: {
		Ttask t1, t2, t3;
		t3 = t2 = t1;
	} break;
	case 3: {
		std::vector<int> vec = { 1,-1, 2, -2, 3, -3, 4, -4 };
		const std::vector<int>::iterator iter = std::remove_if(vec.begin(), vec.end(), [](int a) {return(a < 0); });
		print_vector(vec);
		vec.erase(iter, vec.end());
		print_vector(vec);
	} break;
	case 4: {
		std::vector<int> vec = { 1,-1, 2, -2, 3, -3, 4, -4 };
		print_vector(vec);
		vec.erase(std::remove_if(vec.begin(), vec.end(), [](int a) {return(a < 0); }), vec.end());
		print_vector(vec);
	} break;
	case 5: {
		std::map<std::string, int> m;
		print_map<std::string, int>(m);
		m["a"] = 21;
		print_map<std::string, int>(m);
		m["a"] = 42;
		print_map<std::string, int>(m);
		m["b"] = 77;
		m["c"] = 89;
		print_map<std::string, int>(m);
	} break;
	case 6: {
		std::map<std::string, int> m = { {"a",30}, {"b", 55}, {"c", 78} };
		print_map<std::string, int>(m);

		auto it = m.find("d");
		if (it != m.end())
			std::cout << "key found: " << "m[" << it->first << "]=" << it->second << std::endl;
		else
			std::cout << "key not found " << std::endl;

		std::string arr[] = {"a", "e", "c", "f" };
		for (auto& el : arr)
		{
			(m.find(el) == m.end()) ? std::cout << "<" << el <<"> not found" : std::cout << "m[" << el << "]=" << m[el];
			std::cout << std::endl;
		}


	} break;
	default: {}
	}
	//
	return 0;
}