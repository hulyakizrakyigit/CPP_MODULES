#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    database = other.database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this == &other)
        return *this;
    database = other.database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream dbFile(filename.c_str());
    if (!dbFile.is_open())
        throw std::runtime_error("Could not open file");
    
    std::string line;

    if (!std::getline(dbFile, line))
        throw std::runtime_error("Empty file or read error");
    
    while (std::getline(dbFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            throw std::runtime_error("Bad line format");
        std::string date = line.substr(0, commaPos);
        try {
            float exchange_rate = std::stof(line.substr(commaPos + 1));
            database[date] = exchange_rate;
        } catch (std::exception &e) {
            throw std::runtime_error("Invalid line format");
        }

        if (database.empty())
            throw std::runtime_error("Empty database");
    }
    dbFile.close();

    //hatalı tarih?
    //aynı tarih var mı?
    //tarih sıralı mı?
    //tarihler arası boşluk var mı?
    //boş satır var mı?
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Could not open file");

    std::string line;
    if (!std::getline(inputFile, line)) //date|value içeriyor mu?
        throw std::runtime_error("Empty file or read error");
    
    while (std::getline(inputFile, line)) {
        std::string date;
        float value;

        if (!parseLine(line, date, value)) {
            if (line.find('|') != std::string::npos)
                throw std::runtime_error("Error: not a positive number");
            else
                std::cerr << "Error: bad input => " << line <<std::endl;
        continue;
        }

        std::string closestDate = findClosestDate(date);
        if (closestDate.empty()) {
            std::cerr << "Error: no valid date found for " << date << std::endl;
            continue;
        }

        float rate = database[closestDate];
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
    inputFile.close();
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, float &value) {
    size_t delimiterPos = line.find('|');
    if (delimiterPos == std::string::npos)
        return false;
    date = line.substr(0, delimiterPos);
    std::string valueStr = line.substr(delimiterPos + 1);

    if (date.empty() || valueStr.empty())
        return false; //control
    
    if (isValidDate(date)) 
        return false;

    try {
        value = std::stof(valueStr);
    } catch (...) {
        return false;
    }

    if (value < 0 || value > 100000)
        return false;

    return true;
//boşluk var mı?
//boş satır var mı?
}

bool isValidDate(const std::string &date) {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    return true;
}


std::string BitcoinExchange::findClosestDate(const std::string &date) {
    if (database.find(date) != database.end())
        return date;

    std::string closestDate = "";

    for (std::map<std::string, float>::iterator it = database.begin(); it != database.end(); it++) {
        if (it->first < date)
            closestDate = it->first;
        else
            break;
    }

    return closestDate;
}