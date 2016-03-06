/*****************************************************************************
Program name: grade.c
Author: Wilmer Guerra
Date Submitted: 
Class: CSCI 112
Instructor: Chris Slater
Compiler: Visual Studio 2015
OS: Windows 10 x64
Description: Display averge test scores after user enter in an unknown number of
		     test scores. 
Input Files: none
Output Files: csis.txt
*****************************************************************************/

/*****************************************************************************
Problem: Display averge test scores after user enter in an unknown number of
		 test scores. 
*****************************************************************************/

/*****************************************************************************
Analysis
Inputs: Test scores

Outputs: Average test score

Contraints:
1. Use provided in main function and do not modify.
2. Create and use a calculateAverage function.
3. Use data provided as inputs to program.
4. Output data to csis.txt file.
5. The output should be to two decimal places.
6. Use While loop.
7. Call program grade.c

Formulas:AVG = add up all test scores / number of tests
*****************************************************************************/



/*****************************************************************************
Design
1. Ask user for test scores
	1.1 Use scanf and printf to ask for and gather user input.
	1.2 Keep asking for test scores until user types -1
2. Figure out averge test score
	2.1. add up test scores
	2.2 Divide sum of test scores by number of tests inputed
3. Output results to user
	2.3 use printf to display results to user.
*****************************************************************************/

/*****************************************************************************
Testing 78 + 93 + 45 + 88 + 89 = 393 / 5 = 78.6
12 + 18 = 30 / 2 = 15
*****************************************************************************/

/*****************************************************************************
Implementation
*****************************************************************************/

#include <stdio.h>
FILE *csis;

void calculateAverage();

int main() {
	int i;

	csis = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calculateAverage();
	}
	fclose(csis);
	return 0;
}

void calculateAverage() {
	int numOfTestScores = 0;
	int testUserInput = 0;
	float sumOfTestScores = 0;
	float average;


	while (testUserInput != -1) {
		printf("Type Your Test Score Here (type -1 once you've entered all your scores): ");
		scanf("%d", &testUserInput);

		if (!(testUserInput == -1)) {
			numOfTestScores++;
			sumOfTestScores += testUserInput;
		}
	}

	average = sumOfTestScores / numOfTestScores;
	printf("Your Average Test Score: %.2f\n\n", average);
}