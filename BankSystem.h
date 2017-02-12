#pragma once
#ifndef _BankSystem
#define _BankSystem
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include <fstream>


using namespace std;

class BankSystem
{

private:

	string fname = "", lname = "", id = "";
	double balance = 0, deposit = 0, withdrawl = 0, interest = 0, interestRate = 0.0045;
	int tCount = 0;

public:

	//exception class
	class bsysException {};

	//system functions
	BankSystem();
	~BankSystem();
	BankSystem add();
	const double getBalance();
	void getFirstName(BankSystem& account);
	void getLastName(BankSystem& account);
	void getAccountID(BankSystem& account);
	void makeDeposit(vector<BankSystem>& accounts, int index);
	double getDeposit();
	void makeWithdrawl(vector<BankSystem>& accounts, int index);
	double getWithdrawl();
	void calcInterest(vector<BankSystem>& accounts, int index);
	void displayAccountInfo(vector<BankSystem> accounts, int index);
	void displayAccounts(vector<BankSystem> accounts, int index);
	int selectAccount(vector<BankSystem> accounts, int index);
	void setInterestRate(vector<BankSystem>& accounts, int index);
	void displayMenu(vector<BankSystem> accounts, int index);
	void clearScreen();
	bool isNum(string num);
	bool isAlpha(string str);
	void manageData(vector<BankSystem>& accounts);
	void saveData(vector<BankSystem>& accounts);
	void loadData(vector<BankSystem>& accounts);
	void eraseData(vector<BankSystem>& accounts);
	void setBalanceOutputFormat();
	void setInterestOutputFormat();
	void resetOutputFormat();
	

};

#endif
