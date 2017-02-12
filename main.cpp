#include "BankSystem.h"

int main() {

	vector<BankSystem> accounts; //vector to hold class objects for unique data manipulation
	BankSystem bsys; //object to access class members to modify object data		
	int index = 0;
	bool programFlag = true;
	do {

		bsys.resetOutputFormat();
		bsys.clearScreen();
		bsys.displayMenu(accounts, index);
		int input = _getch();

		switch (input) {

		case '1':
			accounts.push_back(bsys.add());
			break;
		case '2':
			bsys.displayAccounts(accounts, index);
			index = bsys.selectAccount(accounts, index);
			break;
		case '3':
			bsys.makeDeposit(accounts, index);
			break;
		case '4':
			bsys.makeWithdrawl(accounts, index);
			break;
		case '5':
			bsys.displayAccountInfo(accounts, index);
			break;
		case '6':
			bsys.setInterestRate(accounts, index);
			break;
		case '7':
			bsys.manageData(accounts);
			break;
		case '8':
			bsys.clearScreen();
			cout << "Thank you for banking!" << endl;
			cout << endl;
			programFlag = false;
			break;
		}
	} while (programFlag);
	
	return 0;
}