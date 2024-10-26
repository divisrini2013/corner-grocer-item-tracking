#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Author: Divisri
// Date: 2024-10-16

// Class to manage the item tracking functionality
class ItemTracker {
private:
    map<string, int> itemFrequency; // Map to store item frequencies

public:
    // Constructor to initialize itemFrequency
    ItemTracker() {
        // Load data from the input file into the itemFrequency map
        loadData("CS210_Project_Three_Input_File.txt");
        // Create backup file
        createBackup("frequency.dat");
    }

    // Function to load data from the input file
    void loadData(const string& filename) {
        ifstream inputFile(filename); // Open the input file
        string item;

        // Check if the file opened successfully
        if (!inputFile) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        // Read each item from the file and count the frequencies
        while (inputFile >> item) {
            itemFrequency[item]++; // Increment the frequency count for the item
        }
        inputFile.close(); // Close the input file
    }

    // Function to create a backup of frequencies
    void createBackup(const string& filename) {
        ofstream backupFile(filename); // Open the backup file

        // Write item frequencies to the backup file
        for (const auto& entry : itemFrequency) {
            backupFile << entry.first << " " << entry.second << endl; // Format: item frequency
        }
        backupFile.close(); // Close the backup file
    }

    // Function to get frequency of a specific item
    int getItemFrequency(const string& item) {
        return itemFrequency[item]; // Return the frequency of the specified item
    }

    // Function to print the frequency of all items
    void printAllFrequencies() {
        for (const auto& entry : itemFrequency) {
            cout << entry.first << ": " << entry.second << endl; // Print item and its frequency
        }
    }

    // Function to print a histogram of item frequencies
    void printHistogram() {
        for (const auto& entry : itemFrequency) {
            cout << setw(15) << entry.first << " "; // Align item names
            cout << string(entry.second, '*') << endl; // Print asterisks based on frequency
        }
    }
};

// Function to display the menu and handle user input
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Get frequency of a specific item" << endl;
    cout << "2. Print all item frequencies" << endl;
    cout << "3. Print item frequencies as a histogram" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    ItemTracker tracker; // Create an instance of ItemTracker
    int choice;
    string item;

    // Main loop to handle user choices
    do {
        displayMenu(); // Show the menu options
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        switch (choice) {
            case 1:
                cout << "Enter the item you wish to check: ";
                cin >> item; // Get the item from user
                cout << "Frequency of " << item << ": " << tracker.getItemFrequency(item) << endl; // Display frequency
                break;
            case 2:
                tracker.printAllFrequencies(); // Print all item frequencies
                break;
            case 3:
                tracker.printHistogram(); // Print histogram of item frequencies
                break;
            case 4:
                cout << "Exiting the program." << endl; // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again." << endl; // Handle invalid input
        }
    } while (choice != 4); // Loop until user chooses to exit

    return 0; // Indicate successful termination
}
