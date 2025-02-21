#ifndef TRACKER_H
#define TRACKER_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

struct cityData {
    std::string name;
    int population;
    double longitude, latitude;
};

namespace std {
    template <>
    struct hash<cityData> {
        std::size_t operator()(const cityData key) const {
            return hash<std::string>()(key.name);
        }
    };
}

class Tracker {
private:
    std::unordered_map<std::string, cityData> cityMap;

public:
    Tracker();
    Tracker(std::string name, int population, double longitude, double latitude);
    ~Tracker();

    void addCities(std::string name, int population, double longitude, double latitude);
    void updatePopulation(std::string name, int population);
    void removeCity(std::string name);
    cityData cityInfo(std::string name);
    void sortedCity();
    void printCity();
};

#endif 