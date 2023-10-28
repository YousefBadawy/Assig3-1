// ExcelReader.h
#pragma once

#include <vector>
#include <string>

struct ExcelRow {
    std::string city;
    double latitude;
    double longitude;
    std::string country;
};

class ExcelReader {
public:
    static std::vector<ExcelRow> readCSV(const std::string& csvFilePath);
};
