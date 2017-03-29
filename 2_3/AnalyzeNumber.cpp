//Purpose: Break a three-digit number into hundreds digit, tens digit, units digit and print out
//Author: SiAce
//Date: 3/10/2017

#include <iostream>

using namespace std;

int main() {
	int num,hundreds,tens,units = 0;
	cout << "Enter a three-digit number:" << endl;
	cin >> num;
	hundreds = num / 100;
	tens = (num / 10) % 10;
	units = num % 10; //Break the number 
	cout << "As for " << num << ", the hundreds digit is " << hundreds
		<< ", the tens digit is " << tens << ", the units digit is " << units << endl;
	return 0;
}
