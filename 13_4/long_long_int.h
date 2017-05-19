#ifndef LONG_LONG_INT_H_
#define LONG_LONG_INT_H_

class LongLongInt
{
	friend LongLongInt Add(const LongLongInt&, const LongLongInt&);
	friend void Print(const LongLongInt&);
public: 
	LongLongInt(int);
	LongLongInt(char *);
	LongLongInt(const LongLongInt &);
	~LongLongInt();

private:
	int count_;
	int *storage_;
};

LongLongInt Add(const LongLongInt&, const LongLongInt&);
void Print(const LongLongInt&);

#endif // LONG_LONG_INT_H_
