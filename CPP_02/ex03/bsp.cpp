#include "Point.hpp"

static float area(Point const& p1, Point const& p2, Point const& p3) {
    float result = (p1.getX() * (p2.getY() - p3.getY()) + 
                    p2.getX() * (p3.getY() - p1.getY()) + 
                    p3.getX() * (p1.getY() - p2.getY())) / 2.0f;

    return (result >= 0 ? result : -result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float areaABC = area(a, b, c);
    std::cout << "ABC: " << areaABC << std::endl;
    float areaPAB = area(point, a, b);
    std::cout << "PAB: " << areaPAB << std::endl;
    float areaPBC = area(point, b, c);
    std::cout << "PBC: " << areaPBC << std::endl;
    float areaPCA = area(point, c, a);
    std::cout << "PCA: " << areaPCA << std::endl;

    float epsilon = 0.0001f;
    float diff = areaABC - (areaPAB + areaPBC + areaPCA);

    if (diff < 0)
        diff = -diff;

    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return false;

    return (diff < epsilon);
}
