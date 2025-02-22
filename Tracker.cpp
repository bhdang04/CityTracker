#include "Tracker.h"

Tracker::Tracker() {
    
}

Tracker::Tracker(std::string name, int population, double longitude, double latitude) {
    cityMap[name] = { name, population, longitude, latitude };
}

Tracker::~Tracker() {
    cityMap.clear();
}

void Tracker::addCities(std::string name, int population, double longitude, double latitude) {
    cityData& inputData = cityMap[name];
    inputData.name = name;
    inputData.population = population;
    inputData.longitude = longitude;
    inputData.latitude = latitude;
}

void Tracker::updatePopulation(std::string name, int population) {
    if (cityMap.find(name) != cityMap.end()) {
        cityMap[name].population = population;
    }
}

void Tracker::removeCity(std::string name) {
    if (cityMap.empty()) {
        return;
    }

    if (cityMap.find(name) != cityMap.end()) {
        cityMap.erase(name);
    } else {
        std::cout << "There is no City on the list" << std::endl;
    }
}

cityData Tracker::cityInfo(std::string name) {
    if (cityMap.find(name) != cityMap.end()) {
        std::cout << "Name: " << cityMap[name].name << std::endl
            << "Population: " << cityMap[name].population << std::endl
            << "Longitude: " << cityMap[name].longitude << std::endl
            << "Latitude: " << cityMap[name].latitude << std::endl;
    }
    return {};
}

void Tracker::sortedCity() {
    if (cityMap.empty()) {
        return;
    }

    std::map<std::string, cityData> orderedMap;

    for (auto& [name, city] : cityMap) {
        orderedMap[name] = cityData {city.name, city.population, city.longitude, city.latitude};
    }
}

void Tracker::printCity() {
    for (const auto& name : cityMap) {
        cityInfo(name.first);
    }
}