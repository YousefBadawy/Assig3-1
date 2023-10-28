// CityData.cpp
#include "CityData.h"

CityData::CityData(const DMS& latitude, const DMS& longitude, const std::string& country)
    : latitude(latitude), longitude(longitude), country(country) {}
