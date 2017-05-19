#include "long_long_int.h"
#include <iostream>

using namespace std;

LongLongInt::LongLongInt(int count) {
	count_ = count;
	storage_ = new int[count_];
	for (int i = 0; i < count_; i++) {
		storage_[i] = 0;
	}
}

LongLongInt::LongLongInt(char *ch) :
	count_(0)
{
	int i = 0;
	char *p = ch;
	while (*p != '\0') {
		++count_;
		++p;
	}
	storage_ = new int[count_];
	p = ch;
	while (*p != '\0') {
		storage_[i] = *p - '0';
		++i;
		++p;
	}
}

LongLongInt::LongLongInt(const LongLongInt &long_long_int)
{
	count_ = long_long_int.count_;
	storage_ = new int[count_];
	for (int i = 0; i < count_; i++) {
		storage_[i] = long_long_int.storage_[i];
	}
}

LongLongInt::~LongLongInt()
{
	if (storage_) {
		delete[] storage_;
	}
}

LongLongInt Add(const LongLongInt& lhs, const LongLongInt& rhs) {
	if (lhs.count_ > rhs.count_) {
		LongLongInt long_long_int(lhs.count_ + 1);

		for (int i = 1; i <= rhs.count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				lhs.storage_[lhs.count_ - i] + rhs.storage_[rhs.count_ - i];
		}

		for (int i = rhs.count_ + 1; i <= lhs.count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				lhs.storage_[lhs.count_ - i];
		}

		for (int i = 1; i <= long_long_int.count_ - 1; i++) {
			long_long_int.storage_[long_long_int.count_ - i - 1] +=
				long_long_int.storage_[long_long_int.count_ - i] / 10;
			long_long_int.storage_[long_long_int.count_ - i] =
				long_long_int.storage_[long_long_int.count_ - i] % 10;
		}

		if (long_long_int.storage_[0] == 0) {
			LongLongInt long_int_final(long_long_int.count_ - 1);
			for (int i = 0; i < long_long_int.count_ - 1; i++) {
				long_int_final.storage_[i] = long_long_int.storage_[i + 1];
			}
			return long_int_final;
		}
		else {
			return long_long_int;
		}
	}
	else {
		LongLongInt long_long_int(rhs.count_ + 1);

		for (int i = 1; i <= lhs.count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				lhs.storage_[lhs.count_ - i] + rhs.storage_[rhs.count_ - i];
		}

		if (rhs.count_ > lhs.count_) {
			for (int i = lhs.count_ + 1; i <= rhs.count_; i++) {
				long_long_int.storage_[long_long_int.count_ - i] =
					rhs.storage_[rhs.count_ - i];
			}
		}

		for (int i = 1; i <= long_long_int.count_ - 1; i++) {
			long_long_int.storage_[long_long_int.count_ - i - 1] +=
				long_long_int.storage_[long_long_int.count_ - i] / 10;
			long_long_int.storage_[long_long_int.count_ - i] =
				long_long_int.storage_[long_long_int.count_ - i] % 10;
		}

		if (long_long_int.storage_[0] == 0) {
			LongLongInt long_int_final(long_long_int.count_ - 1);
			for (int i = 0; i < long_long_int.count_ - 1; i++) {
				long_int_final.storage_[i] = long_long_int.storage_[i + 1];
			}
			return long_int_final;
		}
		else {
			return long_long_int;
		}
	}
}

void Print(const LongLongInt& long_long_int) {
	int i;
	for (i = 0; i < long_long_int.count_; i++) {
		cout << long_long_int.storage_[i];
	}
	cout << endl;
}

int main() {
	LongLongInt a("123456789");
	LongLongInt b("987654123432");
	LongLongInt c = Add(a, b);
	LongLongInt d = a;
	LongLongInt e("987654");
	LongLongInt f = Add(d, e);
	Print(c);
	Print(f);
	return 0;
}