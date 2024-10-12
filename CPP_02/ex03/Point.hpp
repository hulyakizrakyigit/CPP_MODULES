#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
    const Fixed _x;
    const Fixed _y;

    public:
    Point();
    Point(float x, float y);
    ~Point();
    Point(const Point& other);
    Point& operator=(const Point& other);

    float getX() const;
    float getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif