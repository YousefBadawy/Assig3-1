// CityDictionary.h
#include "BST.h"
#include "CityData.h"
#include "DMS.h"
#include "ExcelReader.h"

class CityDictionary {
public:
    CityDictionary();

    void buildInitialDictionary(const std::string& csvFilePath);
    void saveDictionaryToDisk(const std::string& filePath);
    void loadDictionaryFromDisk(const std::string& filePath);
    void updateDictionary(const std::string& csvFilePath);
    void searchCity(const std::string& cityName);
    void displayAllCities();
    void computeDistanceBetweenCities(const std::string& city1, const std::string& city2);

private:
    BST<std::string, CityData> bstDictionary;

    void saveToDiskRecursive(Node<std::string, CityData>* current, std::ofstream& outFile);
};
