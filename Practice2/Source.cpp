//This program uses an if/else if statement to assign a letter
//grade (A, B, C, D, or F) based on a numeric test score.

#include <iostream>
using namespace std;

int main()
{ 
	int testScore;

	cout << "Enter your test score and I will tell you\n";
	cout << "the letter grade you earned: ";
	cin >> testScore;

	switch (testScore)
		case 1: 
		cout << "Your grade is F.\n";//0-59
	else if (testScore >= 60 && testScore <= 69)
		cout << "Your grade is a D.\n";//60-69
	else if (testScore >= 70 && testScore <= 79)
		cout << "Your grade is a C.\n";//70-79
	else if (testScore >= 80 && testScore <= 89)
		cout << "Your grade is a B.\n";//80-89
	else if (testScore >= 90 && testScore <= 100)
		cout << "Your grade is an A.\n";//90-100

	return 0;

}

