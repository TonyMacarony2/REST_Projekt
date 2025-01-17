#include <iostream>
#include "json.hpp"
#include "ApiHandler.h"

using json = nlohmann::json;
using namespace std;

// Enumeration class used for different input modes
enum class ExecutionMode;

// Call the Menu for user input and display the results
void Menu() {
    ApiHandler apiHandler;

    int choice = 0;
    int number = 1;

    ExecutionMode mode;

    // Validate choice and set execution mode repeatedly until a valid entry is made
    while (true) {
        cout << "================ Welcome to the Menu ================\n";
        cout << "Please choose an option:\n";
        cout << "1. Get Random ZenQuote\n";
        cout << "2. Get Random CatFact\n";
        cout << "===============================================================\n";

        // Get user input for mode selection
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;

        if (cin.fail() || choice <= 0 || choice > 2) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            //cerr << "Invalid number. Please enter either a 1 for ZenQuote or 2 for CatFact\n";
        } else {
            if (choice == 1) {
                mode = ExecutionMode::ZenQuotes;
            } else if (choice == 2) {
                mode = ExecutionMode::MeowFacts;
            }
            break; // Valid input, exit loop
        }
    }

    // Loop to repeatedly ask for a valid number
    while (true) {
        cout << "How many entries would you like to display? ";
        cin >> number;

        // Check for valid input
        if (cin.fail() || number <= 0 || number > 5) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cerr << "Invalid number. Please enter a positive integer from 1 to 5.\n";
        } else {
            break; // Valid input, exit loop
        }
    }

    // Call the display function
    ApiHandler::display_jsonData_formatted(mode, number);
}

int main() {

    Menu();
    return 0;
}
