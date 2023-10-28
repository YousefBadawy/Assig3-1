// ExcelReader.cpp
#include "ExcelReader.h"
#include <fstream>
#include <sstream>

std::vector<std::string> split(const std::string& line, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(line);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<ExcelRow> ExcelReader::readCSV(const std::string& csvFilePath) {
    std::vector<ExcelRow> data;

    std::ifstream inFile(csvFilePath);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << csvFilePath << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::vector<std::string> tokens = split(line, ',');
        if (tokens.size() == 4) {
            ExcelRow row;
            row.city = tokens[0];
            row.latitude = std::stod(tokens[1]);
            row.longitude = std::stod(tokens[2]);
            row.country = tokens[3];
            data.push_back(row);
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    inFile.close();
    return data;
}
