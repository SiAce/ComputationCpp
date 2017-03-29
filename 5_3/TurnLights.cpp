#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

int main() {
	int i,j,n,k;
	cin >> n >> k;
	bool lights[MAXSIZE];
	for (i = 0; i < n; i++) //Initialization
		lights[i] = false;

	for (i = 1; i <= k; i++) { //Turn the lights
		for (j = i; j <= n; j = j + i)
			lights[j-1] = !lights[j-1];
	}

	for (i = 1; i <= n; i++) { //Print out the lights which are on 
		if (lights[i-1]) {
			cout << i << " ";
		}
	}

	return 0;
}