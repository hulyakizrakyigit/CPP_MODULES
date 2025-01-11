#include <iostream>
#include "Array.hpp"
#include <cstdlib>


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        Array<int> test2(5);
        std::cout << "test2[0]: " << test2[0] << std::endl;
        test2 = tmp;
        std::cout << "test2[0]: " << test2[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[2] = 0;
        std::cout << "numbers[2]: " << numbers[2] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "numbers[7]: " << numbers[7] << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "numbers[7]: " << numbers[7] << std::endl;

    delete [] mirror;

    try {
    Array<int> emptyArray;
    std::cout << "emptyArray size: " << emptyArray.size() << std::endl;
    std::cout << "array[0]: " << emptyArray[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try {
    Array<int> array(5);

    array[0] = 1;
    array[1] = 2;
    std::cout << "array[0]: " << array[0] << std::endl;
    std::cout << "array[1]: " << array[1] << std::endl;
    std::cout << "array[8]: " << array[8] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<std::string> strings(4);

    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    strings[3] = "!";
    std::cout << "strings[0]: " << strings[0] << std::endl;
    std::cout << "strings[1]: " << strings[1] << std::endl;
    std::cout << "strings[2]: " << strings[2] << std::endl;
    std::cout << "strings[3]: " << strings[3] << std::endl;

    const Array<std::string> constStrings(strings);
    std::cout << "constStrings[0]: " << constStrings[0] << std::endl;
    std::cout << "constStrings[1]: " << constStrings[1] << std::endl;

    return 0;
}