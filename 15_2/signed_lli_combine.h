#ifndef SIGNED_LLI_COMBINE_H_
#define SIGNED_LLI_COMBINE_H_
#include "long_long_int.h"

class SLLIC
{
	friend istream & operator>>(istream & is, SLLIC &sllic);
	friend ostream & operator<<(ostream & os, const SLLIC &sllic);
	
public:
	SLLIC();
	SLLIC(char * ch);
	bool operator>(const SLLIC &sllic) const;
	bool operator<(const SLLIC &sllic) const;
	bool operator==(const SLLIC &sllic) const;
	SLLIC operator+(const SLLIC &sllic) const;
	SLLIC operator-(const SLLIC &sllic) const;
	SLLIC &operator++();
	SLLIC operator++(int x);
	SLLIC &operator--();
	SLLIC operator--(int x);

private:
	LongLongInt lli_;
	bool sign_;
};

#endif // SIGNED_LLI_COMBINE_H_