#include "Tracker.h"

void exit();

int main() {
    Tracker();
    std::string cityName;
    int choices = 0;
    
    do { 
        cout << "<-------- Choose Options (1-5) -------->" << endl;
        cout << "1. Add to List\n" 
            << "2. Remove to List\n"
            << "3. Manage List\n"
            << "4. View List\n"
            << "5. Quit Application\n";
        cout << "Pick a number to select that option: ";
        cin >> choices;

        system("clear");
        switch (choices) {
            case 1:
                entries = add(entries, toDoArr);
                cout << "Added Successfully" << endl;
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
    cout << "Press Any Key To Exit..." << endl;
    
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