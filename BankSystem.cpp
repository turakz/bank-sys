#include "BankSystem.h"

BankSystem::BankSystem(){
}

BankSystem::~BankSystem(){
}

BankSystem BankSystem::add() {

	clearScreen();
	BankSystem account;
	getFirstName(account);
	getLastName(account);
	getAccountID(account);
	return account;

}

const double BankSystem::getBalance() {

	return balance;

}

void BankSystem::getFirstName(BankSystem& account) {
	
	try {
		clearScreen();
		cout << "First Name: ";
		string tmpstr;
		getline(cin, tmpstr);
		bool checkFlag = isAlpha(tmpstr);
		if (checkFlag) {
			account.fname = tmpstr;
			clearScreen();
		}
		else {
			throw bsysException();
		}
	}

	catch (bsysException) {
	
		clearScreen();
		cout << "Error: input contains a number -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

	}
}
void BankSystem::getLastName(BankSystem& account){

	try {
		clearScreen();
		cout << "Last Name: ";
		string tmpstr;
		getline(cin, tmpstr);
		bool checkFlag = isAlpha(tmpstr);
		if (checkFlag) {
			account.lname = tmpstr;
			clearScreen();

		}
		else {
			throw bsysException();
		}
	}

	catch (bsysException) {

		clearScreen();
		cout << "Error: input contains a number -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

	}

}
void BankSystem::getAccountID(BankSystem& account) {

	try {
		clearScreen();
		cout << "I.D. number: ";
		string tmpstr;
		getline(cin, tmpstr);
		bool checkFlag = isNum(tmpstr);
		if (checkFlag) {
			account.id = tmpstr;
			clearScreen();

		}
		else {
			throw bsysException();
		}
	}

	catch (bsysException) {

		clearScreen();
		cout << "Error: not a number -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');


	}

}

void BankSystem::makeDeposit(vector<BankSystem>& account, int index) {

	if (!account.empty()) {
		account[index].deposit = getDeposit();
		account[index].balance += account[index].deposit;
		calcInterest(account, index);
		++account[index].tCount;
	}
	else {
		clearScreen();
		cout << "No accounts exist -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}

double BankSystem::getDeposit() {

	try {
		clearScreen();
		cout << "Deposit Amount: ";
		string tmp;
		getline(cin, tmp); 
		
		bool checkFlag = isNum(tmp);
		if (!checkFlag) {
			throw bsysException();
		}
		else {
			double dep = stod(tmp);
			return dep;
		}
	}

	catch (bsysException) {
		clearScreen();
		cout << "Error: not a number -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		double dep = 0.0;
		return dep;
	}
		
}

void BankSystem::makeWithdrawl(vector<BankSystem>& account, int index) {

	if (!account.empty()) {
		account[index].withdrawl = getWithdrawl();
		account[index].balance -= account[index].withdrawl;
		calcInterest(account, index);
		++account[index].tCount;
	}
	else {
		clearScreen();
		cout << "No accounts exist -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}

}

double BankSystem::getWithdrawl() {

	try {
		clearScreen();
		cout << "Withdrawl Amount: ";
		string tmp;
		getline(cin, tmp);

		bool checkFlag = isNum(tmp);
		if (!checkFlag) {
			throw bsysException();
		}
		else {
			double wdrawl = stod(tmp);
			return wdrawl;
		}
	}

	catch (bsysException) {
		clearScreen();
		cout << "Error: not a number -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		double wdrawl = 0.0;
		return wdrawl;
	}

}

void BankSystem::calcInterest(vector<BankSystem>& account, int index) {

	account[index].interest = account[index].balance * account[index].interestRate;
	
}

void BankSystem::setInterestRate(vector<BankSystem>& account, int index) {

	if (!account.empty()) {
		clearScreen();
		cout << "New Interest Rate Percentage (decimal form): ";
		double tmp_rate;
		cin >> tmp_rate;
		account[index].interestRate = tmp_rate;
		calcInterest(account, index);
	}
	else {
		clearScreen();
		cout << "No accounts exist -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}

void BankSystem::displayAccountInfo(vector<BankSystem> account, int index) {
	try {
		clearScreen();
		if (account.empty()) {
			throw bsysException();
		}
		else {
			cout << "Account info for " << account[index].fname << " " << account[index].lname << endl;
			cout << endl;
			cout << "ID: " << account[index].id << endl;
			cout << endl;
			setBalanceOutputFormat();
			cout << "Balance: $" << account[index].balance << endl;
			cout << endl;
			setInterestOutputFormat();
			cout << "Interest Rate: %" << account[index].interestRate << endl;
			cout << endl;
			cout << "Balance with %" << account[index].interestRate << " interest: ";
			setBalanceOutputFormat();
			cout << "$" << account[index].interest + account[index].balance << endl;
			cout << endl;
			cout << "Press enter to continue..";
			resetOutputFormat();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	catch (bsysException) {
		cout << "No accounts exist -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}

void BankSystem::displayAccounts(vector<BankSystem> accounts, int index) {

	clearScreen();
	try {
		if (!accounts.empty()) {
			cout << "Currently Editing Account: " << accounts[index].fname << " " << accounts[index].lname << endl;
			cout << endl;
			for (int i = 0; i < accounts.size(); i++) {
				cout << "ID: " << accounts[i].id << " ---- " << accounts[i].fname << " " << accounts[i].lname << endl;
				cout << endl;
			}
		}
		else {
			throw bsysException();
		}
	}

	catch (bsysException) {
	
		//print error before moving into selectAccount()
		cout << "Error: ";

	}
}

int BankSystem::selectAccount(vector<BankSystem> account, int index) {
	try {

		if (account.empty()){
			cout << "No Accounts Exist -- Press enter";
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			return index;
		}
		else {
			cout << "Please enter the I.D. Number: ";
			string tmp_id;
			getline(cin, tmp_id);

			for (int i = 0; i < account.size(); i++) {

				if (account[i].id == tmp_id) {
					tmp_id.clear();
					return i;
				}
			}

			throw bsysException();
		}
	}

	catch (bsysException) {
		clearScreen();
		cout << "Error: Invalid I.D. -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		return index;
	}
}

void BankSystem::displayMenu(vector<BankSystem> accounts, int index) {

	vector<string> menu = {

		"Add a New Account",
		"Select an Account to Manage",
		"Make Deposit",
		"Make Withdrawl",
		"Display Info",
		"Set Interest Rate",
		"Manage Data",
		"Exit System"

	};

	if (!accounts.empty()) {
	
		cout << "BANKING MENU\n";
		cout << endl;
		cout << "Currently Editing Account: " << accounts[index].fname << " " << accounts[index].lname << endl;
		cout << endl;
		cout << "Number of transactions for this session: " << accounts[index].tCount << endl;
		cout << endl;
		for (int i = 0; i < menu.size(); i++) {
			cout << "[" << i + 1 << "]" << setw(5) << setfill('.') << '.' << menu[i] << endl;
			cout << endl;
		}
	}
	else if (accounts.empty()) {
	
		cout << "BANKING MENU\n";
		cout << endl;
		for (int i = 0; i < menu.size(); i++) {
			cout << "[" << i + 1 << "]" << setw(5) << setfill('.') << '.' << menu[i] << endl;
			cout << endl;
		}
	}

	cout << "> ";

}

void BankSystem::clearScreen() {

	system("CLS");

}

bool BankSystem::isNum(string num) {

	vector<char> cvec(num.begin(), num.end());
	for (int i = 0; i < cvec.size(); i++) {
		
		if (cvec[i] == '.'){
			continue;
		}

		else if (!isdigit(cvec[i])) {
			return false;
		}
	}
	return true;
}

bool BankSystem::isAlpha(string str) {


	vector<char> cvec(str.begin(), str.end());
	for (int i = 0; i < cvec.size(); i++) {

		if (!isalpha(cvec[i])) {
			return false;
		}
	}
	return true;
}

void BankSystem::manageData(vector<BankSystem>& accounts) {


	vector<string> menu = {

		"Save Data",
		"Load Data",
		"Erase Data"

	};
	
	clearScreen();
	for (int i = 0; i < menu.size(); i++) {
		cout << "[" << i + 1 << "]" << setw(5) << setfill('.') << '.' << menu[i] << endl;
		cout << endl;
	}
	int input = _getch();
	switch (input) {
	
	case '1':
		saveData(accounts);
		break;
	case '2':
		loadData(accounts);
		break;
	case '3':
		eraseData(accounts);
		break;
	}
}

void BankSystem::saveData(vector<BankSystem>& account) {

	clearScreen();
	ofstream sdata;
	sdata.open("bsysData.txt");
	if (sdata.good()) {
		int index = 0;
		for (int i = 0; i < account.size(); i++) {
		
			sdata << account[index].fname << endl;
			sdata << account[index].lname << endl;
			sdata << account[index].interestRate << endl;
			sdata << account[index].interest << endl;
			sdata << account[index].balance << endl;
			sdata << account[index].id << endl;
			index++;

		}
		cout << "Data Saved -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		sdata.close();
	}
	else {
		cout << "Save data failed, file may not exist -- press enter";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		sdata.close();
	}
	
}
void BankSystem::loadData(vector<BankSystem>& account) {

	clearScreen();
	ifstream ldata;
	ldata.open("bsysData.txt");
	if (ldata.good()) {
	
		BankSystem add;
		while (!ldata.eof()) {
		
			ldata >> add.fname;
			ldata >> add.lname;
			ldata >> add.interestRate;
			ldata >> add.interest;
			ldata >> add.balance;
			if (ldata >> add.id) {
				account.push_back(add);
			}
		}
		cout << "Data Loaded -- press enter";
		ldata.close();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	else {
		cout << "Load data failed, file may not exist -- press enter";
		ldata.close();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	

}

void BankSystem::eraseData(vector<BankSystem>& accounts) {

	clearScreen();
	cout << "WARNING: You are about to delete all system data.. do you wish to continue? y/n: ";
	char choice;
	cin >> choice;
	if (choice == 'y') {
		if (remove("bsysData.txt") != false) {
			clearScreen();
			cout << "Error deleting data file: no such file in directory";
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			clearScreen();
			cout << "Data sucessfully erased!";
			accounts.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	else if (choice == 'n') {
		clearScreen();
		cout << "Press enter to continue";
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
}

void BankSystem::setBalanceOutputFormat() {
	
	cout.imbue(locale(""));
	cout.precision(2);
	cout.setf(ios::fixed);

}

void BankSystem::setInterestOutputFormat() {

	cout.precision(4);
	cout.setf(ios::fixed);

}

void BankSystem::resetOutputFormat() {

	cout.unsetf(ios::fixed);

}


