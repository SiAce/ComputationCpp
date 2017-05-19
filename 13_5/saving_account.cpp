#include "saving_account.h"
#include <iostream>

using namespace std;

double SavingAccount::rate_ = 0.01;
int SavingAccount::number_ = 0;

SavingAccount::SavingAccount(const char *date, double deposit) {
	++number_;
	account_ = number_;
	deposit_ = deposit;
	date_ = date;
}

void SavingAccount::Display() {
	cout << "The deposit is " << deposit_ << "." << endl;
}

void SavingAccount::SetRate(double rate) {
	rate_ = rate;
}

double SavingAccount::RefreshDeposit() {
	deposit_ += deposit_ * rate_;
	return deposit_;
}

int main() {
	SavingAccount account1("20170516", 1000);
	SavingAccount account2("20170517", 2000);
	SavingAccount account3("20170518", 3000);
	account1.Display();
	account1.RefreshDeposit();
	account1.Display();
	account2.Display();
	account3.Display();
	account1.SetRate(0.02);
	account1.Display();
	account2.RefreshDeposit();
	account2.Display();
	return 0;
}