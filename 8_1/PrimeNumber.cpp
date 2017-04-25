#include<iostream>

using namespace std;

bool isPrime(int n) {

	int i;

	if (n == 1)
		return false;

	if (n == 2 || n == 3)
		return true;

	for (i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {

	int m, n, i, count;

	count = 0;
	cout << "Please input m, n: ";
	cin >> m >> n;

	for (i = m; i <= n; i++) {
		if (isPrime(i)) {
			++count;
		}
	}

	cout << "Count = " << count << endl;

	return 0;
}