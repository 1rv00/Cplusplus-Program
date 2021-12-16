#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	float initInv, monDep, AnuInt, months, years;  //input variables for the user

	float totalAm, intAmt, yearToInt; //variables for year end balance, interest, year end interest earned


	cout << "*****************************" << endl;
	cout << "********Data Input***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl; //showing the user what input information will be needed to use the application

	system("PAUSE"); // waiting for user input to continue to the next display

	cout << "*********************" << endl;
	cout << "*******Data Input****" << endl; //getting data from user

	cout << "Initial Investment Amount: $"; //how much the user wants to invest initially
	cin >> initInv;

	cout << "Monthly Deposit: $"; //how much does the user want to deposit on a monthly basis
	cin >> monDep;

	cout << "Annual Interest: %"; //the percentage of interest that the user is earning
	cin >> AnuInt;

	cout << "Number of years: "; //how long the user wants their investment to earn interest
	cin >> years;
	months = years * 12;

	system("PAUSE"); //waiting for user input to continue to the next display

	totalAm = initInv; //converts the initial investment amount to the total amount before interest

	cout << "\n\tBalance and Interest Without Additional Monthly Deposits\n"; //balance with only interest and no additional monthly deposists
	cout << "======================================================================\n";
	cout << "Year\t\t Year End Balance \t Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < years; i++) {

		intAmt = (totalAm) * ((AnuInt / 100)); //calculate interest earned in the year

		totalAm = totalAm + intAmt; //year end balance which is initial investment plus interest earned in the year

		cout << (i + 1) << "\t\t $" << fixed << setprecision(2) << totalAm << "\t\t\t\t $" << intAmt << endl;
		//print results only showing two decimal points
	}

	totalAm = initInv; //changes the total amount back to the initial investment for the next display


	cout << "\n\n\tBalance and Interest with Additional Monthly Deposits\n"; //display for user with additional monthly deposits made
	cout << "=======================================================================\n";
	cout << "Year \t\t Year End Balance \t Year End Earned Interest\n";
	cout << "-----------------------------------------------------------------------\n";

	for (int i = 0; i < years; i++) {

		yearToInt = 0; //setting interest back to 0 at the beginning of each year

		for (int j = 0; j < 12; j++) {

			intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12); //calculate interest amount

			yearToInt = yearToInt + intAmt; //interest amount plus year total interest

			totalAm = totalAm + monDep + intAmt; //total amount plus monthly deposits plus interest amount

		}

		cout << (i + 1) << "\t\t $" << fixed << setprecision(2) << totalAm << "\t\t\t $" << yearToInt << "\n";
		//print results showing only two decimal points
	}

	return 0;

}
