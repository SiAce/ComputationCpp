#ifndef SIGNED_LLI_INHERIT_H_
#define SIGNED_LLI_INHERIT_H_
#include "long_long_int.h"

class SLLII:public LongLongInt
{
	friend istream & operator>>(istream & is, SLLII &sllii);
	friend ostream & operator<<(ostream & os, const SLLII &sllii);

public:
	SLLII();
	SLLII(char * ch);
	SLLII(bool sign, LongLongInt &lli);
	bool operator>(const SLLII &sllii) const;
	bool operator<(const SLLII &sllii) const;
	bool operator==(const SLLII &sllii) const;
	SLLII operator+(const SLLII &sllii) const;
	SLLII operator-(const SLLII &sllii) const;
	SLLII &operator++();
	SLLII operator++(int x);
	SLLII &operator--();
	SLLII operator--(int x);

private:
	bool sign_;
};

#endif // SIGNED_LLI_INHERIT_H_