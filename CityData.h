// CityData.h
#pragma once
#include "DMS.h"
#include <string>

class CityData {
public:
    DMS latitude;
    DMS longitude;
    std::string country;

    CityData(const DMS& latitude, const DMS& longitude, const std::string& country);
};
