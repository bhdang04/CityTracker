#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

namespace std {
    template <>
    struct hash<CityRecord> {
        std::size_t operator()(const CityRecord& key) const {
            return hash<std::string>()(key.cityName);
        }
    };
}

struct cityData {
    std::string name;
    int population;
    double longitude, latitude;
};

class Tracker {
private:
std::unordered_map<std::string, cityData> cityMap;

public:
    Tracker();
    Tracker(std::string name, int population, double longitude, double latitude);
    ~Tracker();

    void addCities(std::string name, double longitude, double latitude);
    void updatePopulation(int population);
    void removeCity(std::string name);
    cityData cityInfo(std::string name);
    void sortedCity();
    void printCity();
};