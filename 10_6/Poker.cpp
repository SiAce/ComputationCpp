#include <iostream>

using namespace std;

const char *suit[4] = { "Spades", "Hearts", "Clubs", "Diamonds" };
const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six",
"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
int deck[52];
int index = 0, i = 0;

void Swap(int &x, int &y);
int Func(void(*p)(int times), int times);
void Shuffle(int times);
void Deal(int times);


int main() {

	bool quit = false;
	int times = 10;
	char choice;

	for (i = 0; i < 52; i++) {
		deck[i] = i;
	}

	while (!quit) {
		cout << "q: quit; 1: shuffle; 2: deal;" << endl;
		cin >> choice;

		switch (choice) {
		case 'q':
			quit = true;
			break;
		case '1':
			cout << "How many times?" << endl;
			cin >> times;
			Func(Shuffle, times);
			break;
		case '2':
			cout << "How many cards?" << endl;
			cin >> times;
			Func(Deal, times);
			break;
		default:
			cout << "Please enter a valid value" << endl;
		}
	}
	
	return 0;
}

void Swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

int Func(void(*p)(int times), int times) {

	p(times);

	return 0;
}

void Shuffle(int times) {

	for (i = 0; i < times; i++) {
		Swap(deck[index + rand() % (52 - index)], deck[index + rand() % (52 - index)]);
	}

}

void Deal(int times) {

	int old_index = index;

	for (i = index; i < old_index + times; i++) {
		cout << face[deck[i] % 13] << " " << suit[deck[i] / 13] << "    ";
		if (index == 51) {
			index = -1;
			cout << "\nAll cards are dealt. Deal from beginning again." << endl;
		}
		++index;
	}
	cout << endl;

}