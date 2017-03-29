#include <iostream>
using namespace std;

const int maxsize = 80;

int main() {
	int i,j,size;
	char tmp;
	bool flag;
	char ch[maxsize];

	cout << "Please input a string:";
	cin.getline(ch, maxsize);

	for (i = 0; ch[i] != '\0';i++) //Get the size of the string 
		size = i+1;

	for (i = 1; i <= size; i++) { //Rank the string by ASCII
		flag = false;
		for (j = 1; j <= size - i; j++) {
			if (ch[j - 1] < ch[j]) {
				tmp = ch[j - 1];
				ch[j - 1] = ch[j];
				ch[j] = tmp;
			}
		}
		if (flag)
			break;
	}

	for (i = 1; i <= size; i++) { //Eliminate the repeated char
		while (ch[i - 1] == ch[i]) {
			for (j = i; j <= size; j++) {
				ch[j - 1] = ch[j];
			}
			size--;
		}
	}

	for (i = 1; i <= size; i++) { //Print out the string
		cout << ch[i - 1];
	}

	return 0;
}