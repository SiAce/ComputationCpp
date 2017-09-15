#ifndef LONG_LONG_INT_H_
#define LONG_LONG_INT_H_
#include <iostream>

using namespace std;

class LongLongInt
{
	friend ostream & operator<<(ostream & os, const LongLongInt &lli);
public:
	LongLongInt();
	LongLongInt(int);
	LongLongInt(char *);
	LongLongInt(const LongLongInt &);
	bool operator>(const LongLongInt &lli) const;
	bool operator<(const LongLongInt &lli) const;
	bool operator==(const LongLongInt &lli) const;
	LongLongInt operator+(const LongLongInt &rhs) const;
	LongLongInt operator-(const LongLongInt &rhs) const;
	LongLongInt & operator=(const LongLongInt &rhs) ;
	LongLongInt & operator=(char * ch) ;
	~LongLongInt();

protected:
	int count_;
	int *storage_;
};

#endif // LONG_LONG_INT_H_
