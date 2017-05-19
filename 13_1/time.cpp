#include "time.h"
#include <iostream>

using namespace std;

void Time::print() {
	cout << "It's " << hours_ << " hours, " << minutes_
		<< " minutes and " << seconds_ << " seconds." << endl;
}

int main() {
	Time my_time1(3, 44, 4);
	Time my_time2(23, 55);
	Time my_time3(35);
	Time my_time4;

	my_time1.print();
	my_time2.print();
	my_time3.print();
	my_time4.print();
	return 0;
}