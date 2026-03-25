#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}


// other tests
//int main(void)
//{
//	Fixed a;
//	Fixed b(5.1f);
//	Fixed c(10);
//	std::cout << c << std::endl;
//	a = c + b;
//	std::cout << a << std::endl;
//	std::cout << c / b << std::endl;
//	std::cout << --a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a-- << std::endl;
//	std::cout << a << std::endl;
//	std::cout << Fixed::min(a, b) << std::endl;
//}