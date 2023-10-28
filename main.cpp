// main.cpp
#include "CityDictionary.h"
#include <iostream>

void printMenu() {
    std::cout << "===== Menu =====\n";
    std::cout << "1. Build Initial Dictionary from CSV\n";
    std::cout << "2. Save Dictionary to Disk\n";
    std::cout << "3. Load Dictionary from Disk\n";
    std::cout << "4. Update Dictionary from CSV\n";
    std::cout << "5. Search City\n";
    std::cout << "6. Display All Cities\n";
    std::cout << "7. Compute Distance Between Cities\n";
    std::cout << "8. Exit\n";
}

int main() {
    CityDictionary cityDict;

    int choice;
    std::string csvFilePath;

    do {
        printMenu();
        std::cout << "Enter your choice (1-8): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter CSV file path: ";
            std::cin >> csvFilePath;
            cityDict.buildInitialDictionary(csvFilePath);
            break;
        case 2:
            std::cout << "Enter file path to save: ";
            std::cin >> csvFilePath;
            cityDict.saveDictionaryToDisk(csvFilePath);
            break;
        case 3:
            std::cout << "Enter file path to load: ";
            std::cin >> csvFilePath;
            cityDict.loadDictionaryFromDisk(csvFilePath);
            break;
        case 4:
            std::cout << "Enter CSV file path to update: ";
            std::cin >> csvFilePath;
            cityDict.updateDictionary(csvFilePath);
            break;
        case 5:
            std::cout << "Enter city name to search: ";
            std::string cityName;
            std::cin >> cityName;
            cityDict.searchCity(cityName);
            break;
        case 6:
            cityDict.displayAllCities();
            break;
       /* case 7:
            
            break;*/
        case 8:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}
