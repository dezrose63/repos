/*Show tickets go for a regular price of $20. 
Children under the age of 2 are free. 
Children at the age of 2 – 5 (inclusive) get a 50% discount. 
Customers at age of 6 – 18 (inclusive) get 25% discount 
and senior citizens 65 years and older get a 40% discount.
Write a program that prompts the user for his age, calculates his ticket price and displays it.*/
#include <iostream>
int main() {  
using namespace std;
// Declare variables
    const double ticketPrice = 20.00; // Regular ticket price
    double userAge;  
	double salesAmount;
	double total;

   // Prompt for age  
   cout << "Enter your age: ";  
   cin >> userAge;  

   // Determine discount based on age  
   if (userAge >= 65)
   {  
	   salesAmount = ticketPrice * .40; 
	   total = ticketPrice - salesAmount; // 40% discount for seniors
   }  
   else if (userAge >= 6 && userAge <= 18)
   {
	   salesAmount = ticketPrice * .25;
	   total = ticketPrice - salesAmount; // 25% discount for age 6-18
   }  
   else if (userAge >= 2 && userAge <= 5)
   {
	   salesAmount = ticketPrice * .50; 
	   total = ticketPrice - salesAmount; // 50% discount for age 2-5
   }
   else if (userAge < 2)
   {
	  total = 0.00;   // Free for children under 2
   }
   else
   {
	   total = ticketPrice;   // Regular price for ages not covered above
   }
   // Display the ticket price
   cout << "Your ticket price is: $" << total << endl;
   return 0;  
}