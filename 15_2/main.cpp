#include "long_long_int.h"
#include "signed_lli_combine.h"
#include "signed_lli_inherit.h"

int main() {

	SLLIC sllic1, sllic2, sllic3;
	cin >> sllic1 >> sllic2 >> sllic3;
	cout << (sllic1 > sllic2) << endl;
	cout << (sllic1 < sllic3) << endl;
	cout << sllic1 + sllic2;
	cout << sllic1 - sllic3;
	sllic1++;
	cout << sllic1;
	--sllic1;
	cout << sllic1;

	SLLII sllii1, sllii2, sllii3;
	cin >> sllii1 >> sllii2 >> sllii3;
	cout << (sllii1 > sllii2) << endl;
	cout << (sllii1 < sllii3) << endl;
	cout << sllii1 + sllii2;
	cout << sllii1 - sllii3;
	sllii1++;
	cout << sllii1;
	--sllii1;
	cout << sllii1;

	return 0;
}