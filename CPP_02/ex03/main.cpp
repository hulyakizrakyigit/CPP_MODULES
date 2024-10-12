#include <iostream>
#include "Point.hpp"

int main( void ) {
    Point a;
    Point b(5, 0);
    Point c(0, 5);
    Point p(1, 1);

    if (bsp(a, b, c, p)) {
        std::cout << "Point is in the triangle" << std::endl;
        std::cout << "\033[32mTRUE\033[0m" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
        std::cout << "\033[31mFALSE\033[0m" << std::endl;
    }

    Point d(-1.5f, -1.5f);
	Point e(2.5f, 2.5f);
	Point f(-1, -2);
	Point point(8.5f, -9);

    if (bsp(d, e, f, point)){
        std::cout << "Point is in the triangle" << std::endl;
        std::cout << "\033[32mTRUE\033[0m" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
        std::cout << "\033[31mFALSE\033[0m" << std::endl;
    }

return 0;
}
