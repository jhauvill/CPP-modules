#include "Point.hpp"

static void print_bool(bool n)
{
	if (n == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
}

int main(void)
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);
	Point point(1, 1);
	bool res = bsp(a, b, c, point);
	print_bool(res);

	Point point1(10, 10);
	res = bsp(a, b, c, point1);
	print_bool(res);

	Point point2(0, 2);
	res = bsp(a, b, c, point1);
	print_bool(res);
	return 0;
}