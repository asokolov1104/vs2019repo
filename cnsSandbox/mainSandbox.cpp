//
#include <iostream>
//
char* data()
{
	char buf[12];
	strncpy_s(buf, "Test", 12);
	return buf;
}
//
auto main() -> int
{
	auto a = 1, b = 2, c = 3;
	a = b = c;
	std::cout << "a = " << a << std::endl;

	typedef struct list_s
	{
		list_s *next;
		int data;
	} list_t;

	list_t list_b;
	list_b.next = NULL;
	list_b.data = b;

	list_t list_a;
	list_a.next = &list_b;
	list_a.data = a;

	//list_a.next = (list_t*)malloc(sizeof(list_t))->next = list_a.next ;

	char* c = data();
	std::cout << "c=" << c << std::endl;

	return 0;
}