#include<iostream>
#include<fstream>
#include<cstdlib>
#include "bankHead.h"
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;

int main()
{
	accountQuery acct;

	int choice;

	cout << "Account Information System " << endl;

	while (true)
	{
		cout << "Select one option " << endl;
		cout << "\n\t Add record to file " << endl;
		cout << "\n\t Show record from file " << endl;
		cout << "\n\t Search record from file " << endl;
		cout << "\n\t Update record " << endl;
		cout << "\n\t Delete record " << endl;
		cout << "\n\t Quit " << endl;
		cout << "\nEnter your choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1: 
			acct.writeRecord();
			break;
		case 2:
			acct.readRecord();
			break;
		case 3:
			acct.searchRecord();
			break;
		case 4:
			acct.editRecord();
			break;
		case 5:
			acct.deleteRecord();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "\nEnter correct choice";
			exit(0);
		}
	}
	system("pause");
	return 0;
}