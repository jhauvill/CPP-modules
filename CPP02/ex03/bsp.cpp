#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed subTriangle1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) 
							- (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed subTriangle2 = (c.getX() - b.getX() * (point.getY() - b.getY())
							- (c.getY() - b.getY()) * (point.getX() - b.getX()));
	Fixed subTriangle3 = (a.getX() - c.getX() * (point.getY() - c.getY())
							- (a.getY() - c.getY()) * (point.getX() - c.getX()));
	Fixed res(subTriangle1 * subTriangle2 * subTriangle3);
	if (res > 0)
		return true;
	return false;
}
