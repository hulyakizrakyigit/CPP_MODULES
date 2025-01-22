#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cctype>

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
    
    if (line.find("date") == std::string::npos || line.find("exchange_rate") == std::string::npos)
        throw std::runtime_error("Bad header in csv file");
    
    while (std::getline(dbFile, line)) {
        if (line.empty())
            continue;
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << "Error: Bad line format: " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, commaPos);
        if (!isValidDate(date)) {
            std::cerr << "Error: Bad date format: " << date << std::endl;
            continue;
        }

        float exchange_rate = std::atof(line.substr(commaPos + 1).c_str());
        database[date] = exchange_rate;
    }
    if (database.empty())
            throw std::runtime_error("Empty database");

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
    if (!std::getline(inputFile, line))
        throw std::runtime_error("Empty file or read error");

    if (line.find("date") == std::string::npos || line.find("value") == std::string::npos)
        throw std::runtime_error("Bad header");
    
    while (std::getline(inputFile, line)) {
        if (line.empty())
            continue;
        std::string date;
        float value;

        int parseResult = parseLine(line, date, value);
        if (parseResult == 1) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (parseResult == 2) {
            std::cerr << "Error: Bad date format " << date << std::endl;
            continue;
        }
        if (parseResult == 3) {
            std::cerr << "Error: Bad value format: " << line << std::endl;
            continue;
        }
        if (parseResult == 4) {
            std::cerr << "Error: not a positive number."<< std::endl;
            continue;
        }
        if (parseResult == 5) {
            std::cerr << "Error: too large a number."<< std::endl;
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

int BitcoinExchange::parseLine(const std::string &line, std::string &date, float &value) {
    size_t delimiterPos = line.find('|');

    date = line.substr(0, delimiterPos);
    std::string valueStr = line.substr(delimiterPos + 1);

        if (delimiterPos == std::string::npos)
        return 1;

    if (!isValidDate(date)) 
        return 2;

    value = std::atof(valueStr.c_str());
    if (value == 0 && valueStr != "0" && valueStr != "0.0") 
        return 3;

    if (value < 0)
        return 4;
    
    if (value > 1000)
        return 5;

    return 0;
//boşluk var mı?
//boş satır var mı?
}

struct IsSpace {
    bool operator()(char c) const {
        return std::isspace(static_cast<unsigned char>(c));
    }
};

bool BitcoinExchange::isValidDate(std::string &date) {
    date.erase(std::remove_if(date.begin(), date.end(), IsSpace()), date.end());

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

    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
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