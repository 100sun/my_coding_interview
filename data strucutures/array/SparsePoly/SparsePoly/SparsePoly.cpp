#include <iostream>

using namespace std;

int main()
{
	int bthMth, bthYr;
	int curMth, curYr;
	int ageYr, ageMth;

	cout << "\n\n\tAge Calculator\n\n";

	cout << "Enter Your Birth Year(Eg:1999):\n";
	cin >> bthYr;
	cout << "\n\nEnter Your Birth Month(Eg:11):\n";
	cin >> bthMth;
	cout << "\nEnter The Current Month(Eg:11):\n";
	cin >> curMth;
	cout << "\nEnter The Current Year(Eg:2010):\n";
	cin >> curYr;

	ageYr = curYr - bthYr;
	ageMth = 12 - bthMth;
	cout << "\n\n\tYour Age is " << ageYr << " Years And " << ageMth << " Months ";

	return 0;
}