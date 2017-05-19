#ifndef TIME_H_
#define TIME_H_

class Time
{
public:
	Time():
		hours_(0), minutes_(0), seconds_(0) {}
	Time(int seconds): 
		hours_(0), minutes_(0), seconds_(seconds) {}
	Time(int minutes, int seconds): 
		hours_(0), minutes_(minutes), seconds_(seconds) {}
	Time(int hours, int minutes, int seconds):
		hours_(hours), minutes_(minutes), seconds_(seconds) {}
	void print();

private:
	int hours_;
	int minutes_;
	int seconds_;
};

#endif // TIME_H_