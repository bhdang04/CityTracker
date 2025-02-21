#include "Tracker.h"

Tracker::Tracker() {
    cityMap[""] = cityData { };
}

Tracker::Tracker(std::string name, int population, double longitude, double latitude) {
    cityMap[name] = cityData { name, population, longitude, latitude };
}

Tracker::~Tracker() {

}

void Tracker::addCities(std::string name, double longitude, double latitude) {
    cityData& inputData = cityMap[name];
    inputData.this->name = name;
    inputData.this->longitude = longitude;
    inputData.this->latitude = latitude;
}

void Tracker::updatePopulation(std::string name, int population) {
    cityData& inputData = cityMap[name];
    inputData.this->population = population;
}

void Tracker::removeCity(std::string name) {
    if (cityMap.empty()) {
        return;
    }

    if (cityMap.find(name) == cityMap.end()) {
        std::cout << "There is no City on the list" << std::endl;
        return;
    } else {
        cityMap.erase(name);
    }
}

void Tracker::cityInfo(std::string name) {
    std::cout << "Name: " << name << std::endl
        << "Population: " << cityMap[name].population << std::endl
        << "Longitude:" << cityMap[name].longitude << std::endl
        << "Latitude: " << cityMap[name].latitude << std::endl;
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
    for (auto& name : cityMap) {
        cityInfo(name.first);
    }
}