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

double Tracker::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lat2) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // Formula
    double a = pow(sin(dLat / 2), 2) + 
                pow(sin(dLon / 2), 2) * 
                cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

void Tracker::closestCity(std::string city) {
    double lowest = 0;
    std::string closest = "";
    for (const auto& pair : cityMap) {
        const std::string& name = pair.first;
        const cityData& otherCity = pair.second;

        if (name == city) continue;

        double distance = haversine(cityMap[city].latitude, cityMap[city].longitude,
                                        otherCity.latitude, otherCity.longitude);

        if (distance < lowest) {
            lowest = distance;
            closest = name;
        }
    }

    std::cout << "The closest city to " << city 
        << " is " << closest << " by " << lowest << " K.M.\n";
}