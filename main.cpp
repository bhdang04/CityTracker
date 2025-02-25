#include "Tracker.h"
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

void waitForKeyPress();

int main() {
    Tracker globalMap;
    std::string cityName;
    int cityPopulation;
    double cityLat, cityLong;
    int choices = 0;
    
    do { 
        std::cout << "<-------- Choose Options (1-5) -------->" << std::endl;
        std::cout << "1. Add to Map\n" 
            << "2. Update Population\n"
            << "3. Remove Country\n"
            << "4. Closest City.\n"
            << "5. View List\n"
            << "6. Quit Application\n";
        std::cout << "Pick a number to select that option: ";
        std::cin >> choices;

        system("clear");
        switch (choices) {
            case 1:
                std::cout << "City Name: ";
                std::cin.ignore();
                std::getline(std::cin, cityName);

                std::cout << "City Population: ";
                std::cin >> cityPopulation;

                std::cout << "Latitude: ";
                std::cin >> cityLat;

                std::cout << "Longitude: ";
                std::cin >> cityLong;

                globalMap.addCities(cityName, cityPopulation, cityLat, cityLong);
                std::cout << "Added Successfully" << std::endl;
                waitForKeyPress();
                break;
            case 2:
                std::cout << "Select City: ";
                std::cin.ignore();
                std::getline(std::cin, cityName);

                std::cout << "Update City Population: ";
                std::cin >> cityPopulation;

                globalMap.updatePopulation(cityName, cityPopulation);
                std::cout << "Updated Successfully" << std::endl;
                waitForKeyPress();
                break;
            case 3:
                std::cout << "Select a City to Remove: ";
                std::cin.ignore();
                getline(std::cin, cityName);

                globalMap.removeCity(cityName);
                std::cout << "Removed Successfully" << std::endl;
                waitForKeyPress();
                break;
            case 4:
                std::cout << "Select a starting city: ";
                std::cin.ignore();
                std::getline(std::cin, cityName);
                
                globalMap.closestCity(cityName);
                waitForKeyPress();
                break;
            case 5:
                globalMap.printCity();
                waitForKeyPress();
                break;
            case 6:
                std::cout << "Successfully Closed\n";
                break;
            default: 
                std::cerr << "\nInvalid Option";
                break;               
        }
        system("clear");
    } while (choices != 6);

}

void waitForKeyPress() {
    std::cout << "Press Any Key To Exit..." << std::endl;
    
    // Wait for a key press
    while (!_kbhit()) {
        // Do nothing, just wait for input
    }

    _getch(); // Read the key press
}
