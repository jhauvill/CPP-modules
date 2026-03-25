#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &second)
{
	if (this != &second)
		_value = second.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &second) const
{
	if (this->_value > second._value)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &second) const
{
	if (this->_value < second._value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &second) const
{
	if (this->_value >= second._value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &second) const
{
	if (this->_value <= second._value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &second) const
{
	if (this->_value == second._value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &second) const
{
	if (this->_value != second._value)
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed &second) const
{
	Fixed res;
	res._value = this->_value + second._value;
	return res;
}

Fixed Fixed::operator-(const Fixed &second) const
{
	Fixed res;
	res._value = this->_value - second._value;
	return res;
}

Fixed Fixed::operator*(const Fixed &second) const
{
	float res;
	res = this->toFloat() * second.toFloat();
	Fixed new_fixed(res);
	return new_fixed;
}

Fixed Fixed::operator/(const Fixed &second) const
{
	float res;
	res = this->toFloat() / second.toFloat();
	Fixed new_fixed(res);
	return new_fixed;
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

Fixed::~Fixed()
{
}
int Fixed::getRawBits() const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt() const
{
	return this->_value >> this->_fractionalBits;
}

float Fixed::toFloat() const
{
	return float(this->_value) / (1 << this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}


Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first._value < second._value)
		return first;
	return second;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first._value > second._value)
		return first;
	return second;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first._value < second._value)
		return first;
	return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first._value > second._value)
		return first;
	return second;
}
