#include <iostream>

using namespace std;

char *encryption(char *str, int key[]) {

	char *p = str;
	int i = 0;

	while (*p != '\0') {
		*p = (*p + key[i] - 32) % 91 + 32;
		++p;
		i = (i + 1) % 7;
	}

	return str;
}

char *decryption(char *str, int key[]) {

	char *p = str;
	int i = 0;

	while (*p != '\0') {
		*p = (*p - key[i] + 59) % 91 + 32;
		++p;
		i = (i + 1) % 7;
	}

	return str;
}

int main() {
	int flag;
	char text[100];
	int key[] = { 8, 7, 3, 4, 9, 6, 2 };

	cout << "Please enter the string: " << endl;
	cin.getline(text, 100);
	cout << "What do you want to do?" << endl;
	cout << "[1] Encryption" << endl;
	cout << "[2] Decryption" << endl;
	cin >> flag;

	switch (flag) {
		case 1 :
			cout << encryption(text, key);
			break;
		case 2 :
			cout << decryption(text, key);
			break;
		default:
			break;
	}

	return 0;
}