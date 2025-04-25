#include <iostream>
using namespace std;

int main()
{
    // Display student information
    cout << "Student Name: Desiree Rose" << endl;
    cout << "Student Number: 900952044" << endl << endl;

    // Declaration of variables
    float num1, num2, result;
    char operation, again;

    do
    {
        // Prompt user to enter operands and operator
        cout << "Please enter first number, operator & second number: ";
        cin >> num1 >> operation >> num2;

        // Perform calculation based on operator entered by user
        switch (operation)
        {
        case '+': // Addition
            result = num1 + num2;
            break;
        case '-': // Subtraction
            result = num1 - num2;
            break;
        case '*': // Multiplication
            result = num1 * num2;
            break;
        case '/': // Division
            if (num2 != 0)
                result = num1 / num2;
            else
            {
                cout << "Error: Division by zero." << endl;
                continue;
            }
            break;
        default: // Invalid operator
            cout << "Invalid operator. Please enter +, -, *, or /." << endl;
            continue;
        }

        // Display result of the calculation
        cout << "Answer = " << result << endl;

        // Ask if the user wants to perform another calculation
        cout << "\nWould you like to perform another calculation? (y / n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    // Goodbye message
    cout << "Thank you for using the calculator program.\nGoodbye" << endl;

    return 0;
}
