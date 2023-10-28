// main.cpp
#include "CityDictionary.h"
#include <iostream>
using namespace std;
void printMenu() {
    cout << "===== Menu =====\n";
    cout << "1. Build Initial Dictionary from CSV\n";
    cout << "2. Save Dictionary to Disk\n";
    cout << "3. Load Dictionary from Disk\n";
    cout << "4. Update Dictionary from CSV\n";
    cout << "5. Search City\n";
    cout << "6. Display All Cities\n";
    cout << "7. Compute Distance Between Cities\n";
cout << "8. Exit\n";
}

int main() {
    CityDictionary cityDict;

    int choice;
    std::string csvFilePath;

    do {
        printMenu();
        cout << "Enter your choice (1-8): ";
        cin >> choice;

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
            cout << "Enter file path to load: ";
            cin >> csvFilePath;
            cityDict.loadDictionaryFromDisk(csvFilePath);
            break;
        case 4:
            cout << "Enter CSV file path to update: ";
            cin >> csvFilePath;
            cityDict.updateDictionary(csvFilePath);
            break;
        case 5:
            cout << "Enter city name to search: ";
            string cityName;
            cin >> cityName;
            cityDict.searchCity(cityName);
            break;
        case 6:
            cityDict.displayAllCities();
            break;
       /* case 7:
            
            break;*/
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}
