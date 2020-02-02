#include<iostream>
#include<iomanip>
using namespace std;

double payCalc(double hours, double rate) { //not sure if this is correct because it does not find overtime value, might make this part of the main or go back and check for overtime
	if (hours > 4)
		return rate * (40 + (hours - 40)*1.5);
	return rate * hours;
}

double fTaxCalc(double pay, double fTax) {
	return pay * fTax / 100;
}

double sTaxCalc(double pay, double sTax) {
	return pay * sTax / 100;
}

int main() {
	double hours[4], rate[4], fTaxRate[4], sTaxRate[4], gPay[4], fTaxOwed[4], sTaxOwed[4], totTax[4], netPay[4];
	char name[4][20];

	for (int i = 0; i < 4; i++) {//gets all the information from the user
		cout << "Enter employee name: ";
		cin.getline(name[i], 20);
		cout << "Enter hours worked: ";
		cin >> hours[i];
		cout << "Enter hourly rate: ";
		cin >> rate[i];
		cout << "Enter federal tax rate: ";
		cin >> fTaxRate[i];
		cout << "Enter state tax rate: ";
		cin >> sTaxRate[i];
		gPay[i] = payCalc(hours[i], rate[i]);
		fTaxOwed[i] = fTaxCalc(gPay[i], fTaxRate[i]);
		sTaxOwed[i] = sTaxCalc(gPay[i], sTaxRate[i]);
		netPay[i] = gPay[i] - fTaxOwed[i] - sTaxOwed[i];

		cout << endl;
		cin.get();
	}
	//for loop to print out formatted info
	for (int j = 0; j < 4; j++) {//could still be i, made it j for clarity
		//formatted table here
	}
	//feels pretty brute force, but is more efficient than making another for loop
	cout << "Total gross pay: \t\t$" << gPay[0] + gPay[1] + gPay[2] + gPay[3] << endl; //I haven't set the format to dollar amount because that will probably be left over from the loop
	cout << "Total federal tax owed: \t$" << fTaxOwed[0] + fTaxOwed[1] + fTaxOwed[2] + fTaxOwed[3] << endl;
	cout << "Total state tax owed: \t\t$" << sTaxOwed[0] + sTaxOwed[1] + sTaxOwed[2] + sTaxOwed[3] << endl;
	cout << "Total net pay: \t\t\t$" << netPay[0] + netPay[1] + netPay[2] + netPay[3] << endl;
	system("PAUSE");
}