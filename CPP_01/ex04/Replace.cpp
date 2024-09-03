#include "Replace.hpp"

void replacInFile(std::string& filename, std::string& s1, std::string& s2)
{
	std::ifstream infile(filename); // open file
	if (!infile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return;
	}

	std::ofstream outfile(filename + ".replace"); // create file
	if (!outfile.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line)) // read line by line
	{
		size_t pos = 0;
		std::string  new_line;
		while ((pos = line.find(s1, pos)) != std::string::npos) // find s1 in line
		{
			new_line += line.substr(0, pos); // add line before s1
			new_line += s2; // add s2
			line = line.substr(pos + s1.length()); // remove s1 from line
		}
		new_line += line; // add the rest of the line
		outfile << new_line << std::endl; // write line to file
	}
	infile.close();
	outfile.close();
}
