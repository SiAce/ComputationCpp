#ifndef SAVING_ACCOUNT_H_
#define SAVING_ACCOUNT_H_

class SavingAccount
{
public:
	SavingAccount(const char *, double);
	void Display();
	void SetRate(double);
	double RefreshDeposit();

private:
	static double rate_;
	static int number_;
	int account_;
	const char *date_;
	double deposit_;
};

#endif // SAVING_ACCOUNT_H_