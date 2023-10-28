// DMS.h
#pragma once

class DMS {
public:
    double degrees;
    double minutes;
    double seconds;
    char direction;

    DMS(double degrees, double minutes, double seconds, char direction);
};
