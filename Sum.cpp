/*Author: SiAce
Created on 2017-03-24 16:33:22
Purpose: calculate the sum of a+aa+aaa+...+aa...a(the number of a is n).
*/
#include<iostream>

using namespace std;

int main() {
	int i, j, k, a, n, term, sum, production;
	sum = 0;
	cout << "Input a,n:";
	cin >> a >> n;
	for (i = 0; i < n; i++) {
		term = 0;
		for (j = 0; j < i + 1; j++) {
			production = 1;
			for (k = 0; k < j; k++) {
				production *= 10;
			}
			term += a*production;//production = 10^j
		}
		sum += term; //term = aaa..aa, the number of a is i+1
	}
	cout << "Sum=" << sum;
	return 0;
}