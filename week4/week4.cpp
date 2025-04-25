// Phone Dialing Simulation Program
// This program simulates dialing a phone number with specific validation rules.
// It converts alphabetic characters to digits and checks for formatting errors.

#include <iostream>
#include <cctype>      // For toupper
#include <string>
using namespace std;

// Function Prototypes:
// readDials - Reads and validates each digit/character in the phone number
// toDigit - Converts a letter to a corresponding number, validates characters
// AcknowledgeCall - Displays the validated/converted phone number
int readDials(char&, char&, char&, char&, char&, char&, char&, char&);
int toDigit(char&);
void AcknowledgeCall(char, char, char, char, char, char, char, char);

int main() {
    // Display student information before anything else
    cout << "Student Name: Desiree Rose" << endl;
    cout << "Student ID Number: 900952044" << endl << endl;

    // Characters to hold each digit of the phone number
    char d1, d2, d3, d4, d5, d6, d7, d8;
    string input;

    // Infinite loop to prompt user for phone numbers until 'Q' is entered
    while (true) {
        cout << "Enter a phone number (Q to quit): ";
        getline(cin, input);

        // Exit condition if input is 'Q'
        if (toupper(input[0]) == 'Q' && input.length() == 1)
            break;

        // Check that input is exactly 8 characters long
        if (input.length() != 8) {
            cout << "ERROR - Phone number must be 8 characters including hyphen\n";
            continue;
        }

        // Assign input characters to individual digit variables
        d1 = input[0]; d2 = input[1]; d3 = input[2]; d4 = input[3];
        d5 = input[4]; d6 = input[5]; d7 = input[6]; d8 = input[7];

        // Validate the phone number using readDials
        int result = readDials(d1, d2, d3, d4, d5, d6, d7, d8);

        // Process validation result and display appropriate message
        switch (result) {
        case 0:
            AcknowledgeCall(d1, d2, d3, d4, d5, d6, d7, d8);
            break;
        case -1:
            cout << "ERROR - An invalid character was entered\n";
            break;
        case -2:
            cout << "ERROR - Phone number cannot begin with 0\n";
            break;
        case -3:
            cout << "ERROR - Phone number cannot begin with 555\n";
            break;
        case -4:
            cout << "ERROR - Hyphen is not in the correct position\n";
            break;
        }
    }

    // Exit prompt
    cout << "Press any key to continue . . .\n";
    return 0;
}

// readDials: Validates formatting of phone number and converts letters
int readDials(char& d1, char& d2, char& d3, char& d4, char& d5, char& d6, char& d7, char& d8) {
    // Ensure hyphen is in the 4th position
    if (d4 != '-')
        return -4;

    // Reject if number begins with 0
    if (d1 == '0')
        return -2;

    // Reject if number begins with 555
    if (toupper(d1) == '5' && toupper(d2) == '5' && toupper(d3) == '5')
        return -3;

    // Validate and convert each character using toDigit function
    char* digits[] = { &d1, &d2, &d3, &d5, &d6, &d7, &d8 };
    for (int i = 0; i < 7; i++) {
        if (toDigit(*digits[i]) != 0)
            return -1;
    }

    return 0;
}

// toDigit: Converts a letter to a digit based on the phone keypad
// Returns -1 for invalid characters, 0 if valid
int toDigit(char& c) {
    if (isdigit(c)) {
        return 0; // Digit is valid
    }
    else if (isalpha(c)) {
        c = toupper(c); // Convert to uppercase
        if (c >= 'A' && c <= 'C') c = '2';
        else if (c >= 'D' && c <= 'F') c = '3';
        else if (c >= 'G' && c <= 'I') c = '4';
        else if (c >= 'J' && c <= 'L') c = '5';
        else if (c >= 'M' && c <= 'O') c = '6';
        else if (c >= 'P' && c <= 'S') c = '7';
        else if (c >= 'T' && c <= 'V') c = '8';
        else if (c >= 'W' && c <= 'Z') c = '9';
        return 0; // Converted successfully
    }
    else {
        return -1; // Invalid character
    }
}

// AcknowledgeCall: Displays the final validated phone number
void AcknowledgeCall(char d1, char d2, char d3, char d4, char d5, char d6, char d7, char d8) {
    cout << "Phone Number Dialed: ";
    cout << d1 << d2 << d3 << d4 << d5 << d6 << d7 << d8 << endl;
}