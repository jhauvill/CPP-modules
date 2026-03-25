#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float n1, const float n2) : x(n1), y(n2)
{
}

Point::Point(const Point &point) : x(point.x), y(point.y)
{
}

Point &Point::operator=(const Point &)
{
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
