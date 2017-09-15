#include "long_long_int.h"

LongLongInt::LongLongInt()
{
	count_ = 1;
	storage_ = new int[count_];
	storage_[0] = 0;
}

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
	if (*p == '-') {
		p++;
	}
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

bool LongLongInt::operator>(const LongLongInt &lli) const {
	if (this->count_ < lli.count_) {
		return false;
	}
	if (this->count_ > lli.count_) {
		return true;
	}
	for (int i = 0; i < lli.count_; i++) {
		if (this->storage_[i] > lli.storage_[i]) {
			return true;
		}
		if (this->storage_[i] < lli.storage_[i]) {
			return false;
		}
	}
	return false;
}

bool LongLongInt::operator<(const LongLongInt &lli) const {
	if (this->count_ > lli.count_) {
		return false;
	}
	if (this->count_ < lli.count_) {
		return true;
	}
	for (int i = 0; i < lli.count_; i++) {
		if (this->storage_[i] < lli.storage_[i]) {
			return true;
		}
		if (this->storage_[i] > lli.storage_[i]) {
			return false;
		}
	}
	return false;
}

bool LongLongInt::operator==(const LongLongInt &lli) const {
	if (this->count_ != lli.count_) {
		return false;
	}
	for (int i = 0; i < lli.count_; i++) {
		if (this->storage_[i] != lli.storage_[i]) {
			return false;
		}
	}
	return true;
}

LongLongInt LongLongInt::operator+(const LongLongInt &rhs) const {
	if ((*this).count_ > rhs.count_) {
		LongLongInt long_long_int((*this).count_ + 1);

		for (int i = 1; i <= rhs.count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				(*this).storage_[(*this).count_ - i] + rhs.storage_[rhs.count_ - i];
		}

		for (int i = rhs.count_ + 1; i <= (*this).count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				(*this).storage_[(*this).count_ - i];
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

		for (int i = 1; i <= (*this).count_; i++) {
			long_long_int.storage_[long_long_int.count_ - i] =
				(*this).storage_[(*this).count_ - i] + rhs.storage_[rhs.count_ - i];
		}

		if (rhs.count_ > (*this).count_) {
			for (int i = (*this).count_ + 1; i <= rhs.count_; i++) {
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

LongLongInt LongLongInt::operator-(const LongLongInt &rhs) const {
	if (*this < rhs) {
		cout << "Can't minus a larger number" << endl;
		return *this;
	}
	else {
		LongLongInt tmp = rhs;
		for (int i = 0; i < tmp.count_; i++) {
			tmp.storage_[i] = -tmp.storage_[i];
		}
		return *this + tmp;
	}
}

LongLongInt & LongLongInt::operator=(const LongLongInt &rhs) {
	delete[] storage_;
	count_ = rhs.count_;
	storage_ = new int[count_];
	for (int i = 0; i < count_; i++) {
		storage_[i] = rhs.storage_[i];
	}
	return *this;
}

LongLongInt & LongLongInt::operator=(char * ch) {
	delete[] storage_;
	char * p = ch;
	int count = 0;
	while (*p != '\0') {
		count++;
		p++;
	}
	count_ = count;
	storage_ = new int[count_];
	p = ch;
	int i = 0;
	while (*p != '\0') {
		storage_[i] = *p - '0';
		++i;
		++p;
	}
	return *this;
}

ostream & operator<<(ostream & os, const LongLongInt &lli) {
	for (int i = 0; i < lli.count_; i++) {
		os << lli.storage_[i];
	}
	os << endl;
	return os;
}

LongLongInt::~LongLongInt()
{
	if (storage_) {
		delete[] storage_;
	}
}