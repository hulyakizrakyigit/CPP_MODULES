#include "Replace.hpp"

void replacInFile(std::string& filename, std::string& s1, std::string& s2)
{
	std::ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return;
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		std::string  new_line;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			new_line += line.substr(0, pos);
			new_line += s2;
			line = line.substr(pos + s1.length());
		}
		new_line += line;
		outfile << new_line << std::endl;
	}
	infile.close();
	outfile.close();
}
