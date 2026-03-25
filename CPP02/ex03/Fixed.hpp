#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &second);
	bool operator>(const Fixed &second) const;
	bool operator<(const Fixed &second) const;
	bool operator>=(const Fixed &second) const;
	bool operator<=(const Fixed &second) const;
	bool operator==(const Fixed &second) const;
	bool operator!=(const Fixed &second) const;
	Fixed operator+(const Fixed &second) const;
	Fixed operator-(const Fixed &second) const;
	Fixed operator*(const Fixed &second) const;
	Fixed operator/(const Fixed &second) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
	static Fixed &min(Fixed &first, Fixed &second);
	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &min(const Fixed &first, const Fixed &second);
	static const Fixed &max(const Fixed &first, const Fixed &second);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif