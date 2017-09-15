#include "signed_lli_inherit.h"

SLLII::SLLII() : sign_(1), LongLongInt("1")
{
}

SLLII::SLLII(char * ch) : sign_(1), LongLongInt(ch)
{
	if ((*ch) == '-') 
		sign_ = 0;
}

SLLII::SLLII(bool sign, LongLongInt & lli) : sign_(sign), LongLongInt(lli)
{
}

bool SLLII::operator>(const SLLII &sllii) const {
	LongLongInt lli1{ *this }, lli2{ sllii };
	if (this->sign_ > sllii.sign_) {
		return true;
	}
	if (this->sign_ < sllii.sign_) {
		return false;
	}
	if ((sllii.sign_) ^ (lli1 > lli2)) {
		return true;
	}
	return false;
}

bool SLLII::operator<(const SLLII &sllii) const {
	LongLongInt lli1{ *this }, lli2{ sllii };
	if (this->sign_ < sllii.sign_) {
		return true;
	}
	if (this->sign_ > sllii.sign_) {
		return false;
	}
	if ((sllii.sign_) ^ (lli1 < lli2)) {
		return true;
	}
	return false;
}

bool SLLII::operator==(const SLLII &sllii) const {
	LongLongInt lli1{ *this }, lli2{ sllii };
	if (this->sign_ != sllii.sign_) {
		return false;
	}
	if (lli1 == lli2) {
		return true;
	}
	return false;
}

SLLII SLLII::operator+(const SLLII &sllii) const {
	LongLongInt lli1{ *this }, lli2{ sllii }, lli3;
	bool tmpsign;
	if (lli1 > lli2) {
		tmpsign = this->sign_;
		if (this->sign_ == sllii.sign_) {
			lli3 = lli1 + lli2;
		}
		else {
			lli3 = lli1 - lli2;
		}
	}
	else {
		tmpsign = sllii.sign_;
		if (this->sign_ == sllii.sign_) {
			lli3 = lli1 + lli2;
		}
		else {
			lli3 = lli2 - lli1;
		}
	}
	SLLII tmp(tmpsign, lli3);
	return tmp;
}

SLLII SLLII::operator-(const SLLII &sllii) const {
	SLLII tmp = sllii;
	tmp.sign_ = !tmp.sign_;
	return *this + tmp;
}
SLLII & SLLII::operator++() {
	SLLII tmp("1");
	*this = *this + tmp;
	return *this;
}
SLLII SLLII::operator++(int x) {
	SLLII tmp("1");
	SLLII tmp2;
	tmp2 = *this;
	*this = *this + tmp;
	return tmp2;
}
SLLII & SLLII::operator--() {
	SLLII tmp("1");
	*this = *this - tmp;
	return *this;
}
SLLII SLLII::operator--(int x) {
	SLLII tmp("1");
	SLLII tmp2;
	tmp2 = *this;
	*this = *this - tmp;
	return tmp2;
}

istream & operator>>(istream & is, SLLII &sllii) {
	char ch[100];
	is >> ch;
	char *p = ch;
	if ((*p) == '-') {
		sllii.sign_ = 0;
		++p;
	}
	sllii.count_ = 0;
	char *p2 = p;
	while (*p2 != '\0') {
		++sllii.count_;
		++p2;
	}
	sllii.storage_ = new int[sllii.count_];
	int i = 0;
	p2 = p;
	while (*p2 != '\0') {
		sllii.storage_[i] = *p2 - '0';
		++i;
		++p2;
	}
	return is;
}

ostream & operator<<(ostream & os, const SLLII &sllii) {
	if (!sllii.sign_) {
		os << "-";
	}
	LongLongInt lli = sllii;
	os << lli;
	return os;
}
