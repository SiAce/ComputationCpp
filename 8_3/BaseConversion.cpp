#include<iostream>

using namespace std;

void printInt(int n, int base) {

	int quotient = n / base;
	int modulo = n % base;

	if (n != 0) {
		printInt(quotient, base);
		printf("%X", modulo);
	}

	return;
}

int main() {

	int i, n, base;
	cout << "Please input n,base: ";
	cin >> n >> base;

	cout << n << "(10) = ";
	printInt(n, base);
	cout << "(" << base << ")" << endl;

	return 0;
}