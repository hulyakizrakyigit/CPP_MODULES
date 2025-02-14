#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
    virtual const char *what() const throw() {
        return "Value not found";
    }
};

template <typename T>
typename T::iterator easyFind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif