#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array {
    private:
        T* array;
        unsigned int n;
    
    public:
    Array() : array(NULL), n(0) {}
    Array(unsigned int n) : array(new T[n]()), n(n) {}
    Array(const Array &other) : array(new T[other.n]), n(other.n) {
        //std::cout << "Copy constructor" << std::endl;
        for (unsigned int i = 0; i < n; i++) {
            array[i] = other.array[i];
        }
    }
    Array &operator=(const Array &other) {
        //std::cout << "Assignment operator" << std::endl;
        if (this != &other) {
            delete[] array;
            array = new T[other.n];
            n = other.n;
            for (unsigned int i = 0; i < n; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] array;
    }

    T &operator[](unsigned int i) {
        if (i >= n) {
            throw InvalidIndexException();
        }
        return array[i];
    }

    const T &operator[](unsigned int i) const {
        if (i >= n) {
            throw InvalidIndexException();
        }
        return array[i];
    }

    unsigned int size() const {
        return n;
    }

    class InvalidIndexException : public std::exception {
        public:
        virtual const char* what() const throw() {
            return "Invalid index";
        }
    };
};

#endif