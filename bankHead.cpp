#include"bankHead.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using namespace std;

void accountQuery::read() {

	cout << "\n Enter Account Number: " << endl;
	cin >> accountNumber;

	cout << "Enter First Name: " << endl;
	cin >> firstN;

	cout << "Enter Second Name: " << endl;
	cin >> lastN;

	cout << "Enter Balance: " << endl;
	cin >> totalBal;
	
	cout << endl;
}

void accountQuery::show() {

	cout << "Account Number: " << accountNumber << endl;

	cout << "First Name: " << firstN << endl;

	cout << "Last Name: " << lastN << endl;

	cout << "Current Balance: " << totalBal << endl;
	
	cout << endl;
}

void accountQuery::writeRecord() {

	ofstream output;
	output.open("records", ios::binary | ios::app);
	read();
	output.write(reinterpret_cast<char *>(this), sizeof(*this));
	output.close();

}

void accountQuery::readRecord() {

	ifstream input;
	input.open("records", ios::binary);
	if (!input) {

		cout << "Error! File Not Found! " << endl;
		return;
	}

	cout << "\nData from file " << endl;

	while (!input.eof())
	{
		if (input.read(reinterpret_cast<char*>(this), sizeof(*this))>0)
		show();
	}
	input.close();
}

void accountQuery::searchRecord() {

	int num;
	ifstream input;
	input.open("records", ios::binary);

	if (!input) {
		cout << "\nError! File Not Found! " << endl;
		return;
	}
	input.seekg(0, ios:end);
	int count = input.tellg() / sizeof(*this);
	cout << "\n There are " << count << " record in file";
	cout << "\n Enter Record Number to Search: ";
	input.read(reinterpret_cast<char*>(this), sizeof(*this));
	cin >> num;
	input.seekg((num-1)*sizeof(*this));
	input.read(reinterpret_cast<char*>(this), sizeof(*this));
	show();
}

void accountQuery::editRecord() {

	int num;
	fstream out;
	out.open("records", ios::in | ios::binary);
	if (!out) {
		cout << "\nError! File Not Found! " << endl;
		return;
	}
	out.seekg(0, ios::end);
	int count = out.tellg() / sizeof(*this);
	cout << "\n There are " << count << " record in the file";
	cout << "\n Enter the Record Number to Edit: " << endl;
	cin >> num;
	out.seekg((num - 1)* sizeof(*this));
	out.read(reinterpret_cast<char*>(this), sizeof(*this));
	cout << "Record: " << num << " has following data" << endl;
	show();
	out.close();
	out.open("records", ios::out|ios::in|ios::binary);
	out.seekp((num - 1) * sizeof(*this));
	cout << "\nEnter data to modify: " << endl;
	read();
	out.write(reinterpret_cast<char*>(this), sizeof(*this));
}

void accountQuery::deleteRecord() {

	int num;
	ifstream infile;
	infile.open("records", ios::binary);
	if (!infile)
	{
		cout << "\nError in opening! File Not Found!!" << endl;
		return;
	}
	infile.seekg(0, ios::end);
	int count = infile.tellg() / sizeof(*this);
	cout << "\n There are " << count << " record in the file";
	cout << "\n Enter Record Number to Delete: ";
	cin >> num;
	fstream tmpfile;
	tmpfile.open("tmpfile", ios::out | ios::binary);
	infile.seekg(0);
	for (int i = 0; i<count; i++)
	{
		infile.read(reinterpret_cast<char*>(this), sizeof(*this));
		if (i == (num - 1))
			continue;
		tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
	}
	infile.close();
	tmpfile.close();
	remove("records");
	rename("tmpfile", "records");

}