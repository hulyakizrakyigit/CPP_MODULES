#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the string using pointer: " << stringPTR << std::endl;
	std::cout << "Address of the string using reference: " << &stringREF << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "String using pointer: " << *stringPTR << std::endl;
	std::cout << "String using reference: " << stringREF << std::endl;

}
