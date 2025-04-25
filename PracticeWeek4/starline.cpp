// This program demonstrates the use of a simple void function
#include <iostream>
using namespace std;
void starline(); // Declaration (prototype) of function
int main() // Main function. Returns an integer; no params
{
	starline(); // Function call
	cout << "This is a header" << endl;
	starline(); // Another function call
	cout << " This is a block of text" << endl;
		cout << " :" << endl << endl;
	starline(); // Function call
	cout << "This is a trailer" << endl << endl;
	starline();
	return 0;
}
// starline() function definition
void starline()
{
	for (int i = 0; i < 50; i++)
	{
		cout << '*';
	}
	cout << endl;
}
