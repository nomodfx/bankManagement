#ifndef	BANKHEAD_H
#define BANKHEAD_H

class accountQuery {
private:
	char accountNumber[20];
	char firstN[10];
	char lastN[10];
	float totalBal;

public:
	void read();
	void show();
	void writeRecord();
	void readRecord();
	void searchRecord();
	void editRecord();
	void deleteRecord();
};
#endif