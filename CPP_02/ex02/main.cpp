#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "b: " << b << std::endl;

    std::cout << "max(a,b): " << Fixed::max( a, b ) << std::endl;
    std::cout << "min(a,b): " << Fixed::min(a, b) << std::endl;

    std::cout << std::endl;

    Fixed x(1);
    Fixed const y(10);
    Fixed const z(42.42f);
    Fixed const w(y);

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
    std::cout << "w: " << w << std::endl;   

    std::cout << std::endl;

    Fixed result = x + z;
    std::cout << "x + z = " << result << std::endl;

    result = z - y;
    std::cout << "z - y = " << result << std::endl;

    result = y * z;
    std::cout << "y * z = " << result << std::endl;

    result = z / y;
    std::cout << "z / y = " << result << std::endl;

    std::cout << std::endl;

    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "y > z: " << (y > z) << std::endl;
    std::cout << "y <= w: " << (y <= w) << std::endl;
    std::cout << "y >= w: " << (y >= w) << std::endl;
    std::cout << "y == w: " << (y == w) << std::endl;
    std::cout << "x != w: " << (x != w) << std::endl;

    std::cout << std::endl;

    std::cout << "x: " << x << std::endl;
    std::cout << "x++: " << x++ << std::endl;
    std::cout << "x: " << x << std::endl;

    std::cout << std::endl;

    std::cout << "--x: " << --x << std::endl; 
    std::cout << "x--: " << x-- << std::endl; 
    std::cout << "x: " << x << std::endl;

    std::cout << std::endl;

    std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
    std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

return 0;
}
