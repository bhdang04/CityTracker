#include "Tracker.h"
#include <termios.h>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>

void exit();

int main() {
    Tracker globalMap();
    std::string cityName;
    int cityPopulation;
    double cityLat, cityLong;
    int choices = 0;
    
    do { 
        std::cout << "<-------- Choose Options (1-5) -------->" << std::endl;
        std::cout << "1. Add to Map\n" 
            << "2. Update Population\n"
            << "3. Remove Country\n"
            << "4. View List\n"
            << "5. Quit Application\n";
        std::cout << "Pick a number to select that option: ";
        std::cin >> choices;

        system("clear");
        switch (choices) {
            case 1:
                std::cout << "City Name: ";
                std::cin >> cityName;

                std::cout << "City Population: ";
                cin.ignore();
                std::cin >> cityPopulation;

                std::cout << "Latitude: ";
                cin.ignore();
                std::cin >> cityLat;

                std::cout << "Longitude: ";
                cin.ignore();
                std::cin >> cityLong;

                globalMap.addCities(cityName, cityPopulation, cityLat, cityLong);
                std::cout << "Added Successfully" << std::endl;
                exit();
                break;
            case 2:
                entries = remove(entries, toDoArr);
                cout << "Deleted Successfully" << endl;
                exit();
                break;
            case 3:
                manage(entries, toDoArr);
                cout << "Swapped Successfully" << endl;
                exit();
                break;
            case 4:
                view(entries, toDoArr);
                exit();
                break;
            case 5:
                cout << "Successfully Closed\n";
                break;
            default: 
                cerr << "\nInvalid Option";
                break;               
        }
        system("clear");
    } while (choices != 5);

}

void exit() {
    std::cout << "Press Any Key To Exit..." << std::endl;
    
    // Disable buffering and echo
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    // Read a single character
    char ch;
    read(STDIN_FILENO, &ch, 1);

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}