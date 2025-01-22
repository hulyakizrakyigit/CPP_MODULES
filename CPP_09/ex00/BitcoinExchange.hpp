#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange {
    private:
    std::map<std::string, float> database;

    public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);
    int parseLine(const std::string &line, std::string &date, float &value);
    bool isValidDate(std::string &date);
    std::string findClosestDate(const std::string &date);
};

#endif