//
#include <iostream>
#include <deque>
//
auto main() -> int {

	std::deque<int> d;
	printf("deque number elems: %d\n", d.size());
	printf("deque max possible elems: %d\n", d.max_size());
	printf("sizeof of deque: %d\n", sizeof(d));

	//d.push_back(101);
	//d.push_back(102);
	//d.push_back(103);
	//printf("deque number elems: %d\n", d.size());
	//printf("deque max possible elems: %d\n", d.max_size());
	//printf("sizeof of deque: %d\n", sizeof(d));


	//d.push_front(201);
	//d.push_front(302);
	//d.push_front(403);
	//printf("deque number elems: %d\n", d.size());
	//printf("deque max possible elems: %d\n", d.max_size());
	//printf("sizeof of deque: %d\n", sizeof(d));

	for (int i = 0; i < 100; ++i) {
		d.push_front(-i);
		d.push_back(i);
	}
	printf("deque number elems: %d\n", d.size());
	printf("deque max possible elems: %d\n", d.max_size());
	printf("sizeof of deque: %d\n", sizeof(d));

	return 0;
}