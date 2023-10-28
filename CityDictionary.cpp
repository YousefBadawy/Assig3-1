// CityDictionary.cpp
#include "CityDictionary.h"
#include "ExcelReader.h"
#include <fstream>
#include <iostream>
#include <cmath>

const double EARTH_RADIUS_KM = 6371.0; // Earth radius in kilometers

CityDictionary::CityDictionary() {}

void CityDictionary::buildInitialDictionary(const std::string& csvFilePath) {
    // Read data from CSV and insert into the BST
    std::vector<ExcelRow> csvData = ExcelReader::readCSV(csvFilePath);

    for (const auto& row : csvData) {
        CityData cityData(
            DMS(row.latitude.degrees, row.latitude.minutes, row.latitude.seconds, row.latitude.direction),
            DMS(row.longitude.degrees, row.longitude.minutes, row.longitude.seconds, row.longitude.direction),
            row.country);

        bstDictionary.insert(row.city, cityData);
    }
}

void CityDictionary::saveDictionaryToDisk(const std::string& filePath) {
    std::ofstream outFile(filePath);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filePath << std::endl;
        return;
    }

    // Save the BST nodes to a text file on disk using in-order traversal
    saveToDiskRecursive(bstDictionary.getRoot(), outFile);

    outFile.close();
}

void CityDictionary::saveToDiskRecursive(Node<std::string, CityData>* current, std::ofstream& outFile) {
    if (current != nullptr) {
        saveToDiskRecursive(current->left, outFile);
        outFile << current->key << "," << current->data.latitude.degrees << "," << current->data.latitude.minutes
            << "," << current->data.latitude.seconds << "," << current->data.latitude.direction << ","
            << current->data.longitude.degrees << "," << current->data.longitude.minutes << ","
            << current->data.longitude.seconds << "," << current->data.longitude.direction << ","
            << current->data.country << "\n";
        saveToDiskRecursive(current->right, outFile);
    }
}

void CityDictionary::loadDictionaryFromDisk(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filePath << std::endl;
        return;
    }

    // Clear existing dictionary
    bstDictionary.clear();

    // Read data from the file and insert into the BST
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string cityName;
        DMS latitude, longitude;
        std::string country;
        char delimiter;

        if (iss >> cityName >> delimiter >> latitude.degrees >> delimiter >> latitude.minutes >> delimiter >>
            latitude.seconds >> delimiter >> latitude.direction >> delimiter >> longitude.degrees >> delimiter >>
            longitude.minutes >> delimiter >> longitude.seconds >> delimiter >> longitude.direction >> delimiter >>
            country) {
            CityData cityData(latitude, longitude, country);
            bstDictionary.insert(cityName, cityData);
        }
    }

    inFile.close();
}

void CityDictionary::updateDictionary(const std::string& csvFilePath) {
    // Load the existing dictionary from disk into memory
    loadDictionaryFromDisk("your_dictionary_file.txt");

    // Add new cities or update existing ones
    buildInitialDictionary(csvFilePath);

    // Save the updated dictionary back to disk
    saveDictionaryToDisk("your_dictionary_file.txt");
}

void CityDictionary::searchCity(const std::string& cityName) {
    Node<std::string, CityData>* result = bstDictionary.search(cityName);
    if (result != nullptr) {
        std::cout << "City: " << result->key << "\n";
        std::cout << "Latitude: " << result->data.latitude.degrees << "°" << result->data.latitude.minutes << "'"
            << result->data.latitude.seconds << "''" << result->data.latitude.direction << "\n";
        std::cout << "Longitude: " << result->data.longitude.degrees << "°" << result->data.longitude.minutes << "'"
            << result->data.longitude.seconds << "''" << result->data.longitude.direction << "\n";
        std::cout << "Country: " << result->data.country << "\n";
    }
    else {
        std::cout << "City not found.\n";
    }
}

void CityDictionary::displayAllCities() {
    std::cout << "===== All Cities =====\n";
    bstDictionary.inOrderTraverse([](Node<std::string, CityData>* node) {
        std::cout << "City: " << node->key << "\n";
        std::cout << "Latitude: " << node->data.latitude.degrees << "°" << node->data.latitude.minutes << "'"
            << node->data.latitude.seconds << "''" << node->data.latitude.direction << "\n";
        std::cout << "Longitude: " << node->data.longitude.degrees << "°" << node->data.longitude.minutes << "'"
            << node->data.longitude.seconds << "''" << node->data.longitude.direction << "\n";
        std::cout << "Country: " << node->data.country << "\n";
    });
}

void CityDictionary::computeDistanceBetweenCities(const std::string& city1, const std::string& city2) {
    // Get the latitude and longitude of the two cities from the dictionary
    Node<std::string, CityData>* cityNode1 = bstDictionary.search(city1);
    Node<std::string, CityData>* cityNode2 = bstDictionary.search(city2);

    if (cityNode1 == nullptr || cityNode2 == nullptr) {
        std::cerr << "One or both cities not found in the dictionary.\n";
        return;
    }

    // Convert latitude and longitude from degrees, minutes, seconds to decimal degrees
    double lat1 = cityNode1->data.latitude.degrees + cityNode1->data.latitude.minutes / 60.0 +
                  cityNode1->data.latitude.seconds / 3600.0;
    double lon1 = cityNode1->data.longitude.degrees + cityNode1->data.longitude.minutes / 60.0 +
                  cityNode1->data.longitude.seconds / 3600.0;
    double lat2 = cityNode2->data.latitude.degrees + cityNode2->data.latitude.minutes / 60.0 +
                  cityNode2->data.latitude.seconds / 3600.0;
    double lon2 = cityNode2->data.longitude.degrees + cityNode2->data.longitude.minutes / 60.0 +
                  cityNode2->data.longitude.seconds / 3600.0;

    // Calculate the Haversine distance
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
                                                  sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    double distance = EARTH_RADIUS_KM * c;

    std::cout << "Distance between " << city1 << " and " << city2 << ": " << distance << " km\n";
}
