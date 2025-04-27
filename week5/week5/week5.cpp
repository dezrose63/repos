// Project Assignment #5
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structure definition for airport data
struct Airport 
{
    int landings;
    int takeoffs;
    int maxLandingsSingleDay;
    int minLandingsSingleDay;
};

int main() 
{
    cout << "Student Name: \t\tDesiree Rose" << endl;
    cout << "Student ID Number: \t900952044" << endl << endl;

    const int MONTHS = 12;
    string monthNames[MONTHS] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    Airport airportData[MONTHS]{};
    int totalLandings = 0, totalTakeoffs = 0;
    int highestLanding = 0, lowestLanding = 0;
    string highestMonth, lowestMonth;

    // Input airport data for each month
    for (int i = 0; i < MONTHS; i++) 
    {
        cout << "Please enter the number of planes that landed in " << monthNames[i] << ": ";
        cin >> airportData[i].landings;
        while (airportData[i].landings < 0) 
        {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin >> airportData[i].landings;
        }

        cout << "Please enter the number of planes that departed in " << monthNames[i] << ": ";
        cin >> airportData[i].takeoffs;
        while (airportData[i].takeoffs < 0) 
        {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin >> airportData[i].takeoffs;
        }

        cout << "Please enter the greatest number of planes that landed on a single day in " << monthNames[i] << ": ";
        cin >> airportData[i].maxLandingsSingleDay;
        while (airportData[i].maxLandingsSingleDay < 0) 
        {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin >> airportData[i].maxLandingsSingleDay;
        }

        cout << "Please enter the least number of planes that landed on a single day in " << monthNames[i] << ": ";
        cin >> airportData[i].minLandingsSingleDay;
        while (airportData[i].minLandingsSingleDay < 0) 
        {
            cout << "Invalid input. Please enter a non-negative number: ";
            cin >> airportData[i].minLandingsSingleDay;
        }
    }

    // Accumulate total landings and takeoffs
    for (int i = 0; i < MONTHS; i++) 
    {
        totalLandings += airportData[i].landings;
        totalTakeoffs += airportData[i].takeoffs;

        if (i == 0) 
        {
            highestLanding = airportData[i].maxLandingsSingleDay;
            highestMonth = monthNames[i];
            lowestLanding = airportData[i].minLandingsSingleDay;
            lowestMonth = monthNames[i];
        }
        else 
        {
            if (airportData[i].maxLandingsSingleDay > highestLanding) 
            {
                highestLanding = airportData[i].maxLandingsSingleDay;
                highestMonth = monthNames[i];
            }
            if (airportData[i].minLandingsSingleDay < lowestLanding) 
            {
                lowestLanding = airportData[i].minLandingsSingleDay;
                lowestMonth = monthNames[i];
            }
        }
    }

    // Calculate averages
    double averageLandings = static_cast<double>(totalLandings) / MONTHS;
    double averageTakeoffs = static_cast<double>(totalTakeoffs) / MONTHS;

    // Display the results
    cout << fixed << setprecision(2);
    cout << "The average monthly landings for the year is " << averageLandings << endl;
    cout << "The average monthly departures for the year is " << averageTakeoffs << endl;
    cout << "The total landings for the year is " << totalLandings << endl;
    cout << "The total departures for the year is " << totalTakeoffs << endl;
    cout << "The greatest number of planes that landed in a single day is " << highestLanding
        << " which occured in the month of " << highestMonth << endl;
    cout << "The least number of planes that landed in a single day is " << lowestLanding
        << " which occured in the month of " << lowestMonth << endl;
   
    cin.ignore();
    cin.get();
    return 0;
}
