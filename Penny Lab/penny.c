/*****************************************************************************
Program name: penny.c
Author: Wilmer Guerra 008424284
Date Submitted: 3/6/2016
Class: CSCI 112
Instructor: Chris Slater
Compiler: Visual Studio Express 2015 For Windows Desktop
OS: Windows 10 x64
Description: This program will determine how many days it would take to save
			 any given dollar amount. 
Input Files: none
Output Files: csis.txt
*****************************************************************************/



/*****************************************************************************
Problem: On day 1 you deposit 1 penny into the bank. Assuming your deposit doubles
		 everyday, how many days would it take to get to $1,000,000.
*****************************************************************************/



/*****************************************************************************
Analysis
	Inputs: Amount that you want to save. 

	Outputs: How many days it would take to save 1 million dollars. 

	Contraints:
	1. Amount deposited doubles everyday.
	2. The amount we're trying to get to is $1,000,000.
	3. Output has to appear like the table in the book.
	4. Assume no interest is paid.
	5. Include 3 functions: 1 to generate table, 1 to display table header, and the main function.
	6. Input should be double type and should be passed into function to generate table.
	7. Capture data in csis.txt file. 

	Formulas: Deposit of the day is previous deposit * 2. 
*****************************************************************************/



/*****************************************************************************
Design
1. Ask user for amount that needs to be saved.
2. Figure out how many days it would take to save that amount
	2.1.Add deposit of the day to amount saved
		2.1.1 Deposit on first day is .01
	2.2 Move up a day
	2.3 Figure out deposit for current day
		2.3.1. Deposit for current day is previous deposit * 2.
	2.4 Repeat steps 2.1 - 2.3 as long as amount saved is less than amount needed
		to save
3. Display amount to user. 
*****************************************************************************/

/*****************************************************************************
Testing: days it would take to save $1 = 7 days
		 days it would take to save $1000000 = 27
		 days it would take to save $100 = 14
		 
*****************************************************************************/

/*****************************************************************************
Implementation
*****************************************************************************/
#include <stdio.h>

FILE *csis;

double tableHeader();
void generateTable(double);

int main(){
	double amountToSave;
	
	csis = fopen("csis.txt", "w");
	amountToSave = tableHeader();
	printf("\tDAY\t\t\tDEPOSIT\t\t\tBALANCE\n");
	printf("\t---\t\t\t-------\t\t\t-------\n");
	fprintf(csis, "\tDAY\t\t\tDEPOSIT\t\t\tBALANCE\n");
	fprintf(csis, "\t---\t\t\t-------\t\t\t-------\n");
	generateTable(amountToSave);
	fclose(csis);
	
	return 0;
}

double tableHeader() {
	double amountToSave;
	printf("Please enter the amount of money you want to accumulate: ");
	fprintf(csis, "Please enter the amount of money you want to accumulate: ");
	scanf("%lf", &amountToSave);
	fprintf(csis, "%.2lf\n", amountToSave);
	return amountToSave;
}

void generateTable(double amountToSave) {
	double actuallySaved = 0;
	float deposit = .01;
	int day = 1;

	//generating my table
	while (actuallySaved < amountToSave) {
		actuallySaved += deposit;
		printf("\t%3d\t\t%15.2f\t\t%15.2lf\n", day, deposit, actuallySaved);
		fprintf(csis, "\t%3d\t\t%15.2f\t\t%15.2lf\n", day, deposit, actuallySaved);
		deposit *= 2;

		// using if loop so it doesn't add an extra day at the end
		if( actuallySaved < amountToSave)
			day++;
	}


	//outputting result to user
	printf("It took %d days to accumulate at least %.2f\n", day, amountToSave);
	fprintf(csis, "It took %d days to accumulate at least %.2f\n", day, amountToSave);

}