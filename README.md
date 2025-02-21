# CityTracker

CityTracker is a C++ application that allows users to manage and interact with a list of cities. The program lets users add cities, update their population, remove cities, and display the current list of cities with their information.

## Features

- **Add Cities**: Add cities to the map with name, population, latitude, and longitude.
- **Update Population**: Update the population of a specific city.
- **Remove City**: Remove a city from the map by name.
- **View Cities**: View a list of all cities with their details.
- **Sort Cities**: (Future Feature) View cities sorted by a specific attribute (not yet implemented).

## Requirements

- A C++ compiler (e.g., GCC or Clang)
- C++11 or higher
- The `conio.h` library (for Windows users) for handling key presses in the terminal (optional).

## Installation

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/your-username/CityTracker.git
    ```

2. Navigate to the project directory:

    ```bash
    cd CityTracker
    ```

3. Compile the code with a C++ compiler:

    ```bash
    g++ main.cpp Tracker.cpp -o main
    ```

## Usage

1. Run the compiled application:

    ```bash
    ./main
    ```

2. The program will display a menu with the following options:
    - **1**: Add a city to the tracker
    - **2**: Update the population of an existing city
    - **3**: Remove a city from the tracker
    - **4**: View the list of cities
    - **5**: Quit the application

3. Follow the prompts to interact with the program.

## Code Structure

- **main.cpp**: Contains the main entry point for the program and the logic for user interaction.
- **Tracker.cpp**: Defines the methods for the `Tracker` class that manages the city data.
- **Tracker.h**: Header file for the `Tracker` class, which contains the city data and method declarations.
- **cityData**: A structure that holds the city’s name, population, latitude, and longitude.

## Contact

If you have any questions or suggestions, feel free to open an issue on the GitHub repository or contact me directly.

