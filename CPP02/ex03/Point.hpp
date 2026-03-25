#ifndef POINT_CPP
#define POINT_CPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float n1, const float n2);
	Point(const Point &point);
	Point &operator=(const Point &);
	~Point() {};
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif