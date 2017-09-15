#include "signed_lli_combine.h"

SLLIC::SLLIC() : sign_(1), lli_("1") {
}

SLLIC::SLLIC(char * ch): sign_(1)
{
	char *p = ch;
	if ((*p) == '-') {
		sign_ = 0;
		++p;
	}
	lli_ = p;
}

bool SLLIC::operator>(const SLLIC &sllic) const {
	if (this->sign_ > sllic.sign_) {
		return true;
	}
	if (this->sign_ < sllic.sign_) {
		return false;
	}
	if ((sllic.sign_) ^ (this->lli_ > sllic.lli_)) {
		return true;
	}
	return false;
}

bool SLLIC::operator<(const SLLIC &sllic) const {
	if (this->sign_ < sllic.sign_) {
		return true;
	}
	if (this->sign_ > sllic.sign_) {
		return false;
	}
	if ((sllic.sign_) ^ (this->lli_ < sllic.lli_)) {
		return true;
	}
	return false;
}

bool SLLIC::operator==(const SLLIC &sllic) const {
	if (this->sign_ != sllic.sign_) {
		return false;
	}
	if (this->lli_ == sllic.lli_) {
		return true;
	}
	return false;
}

SLLIC SLLIC::operator+(const SLLIC &sllic) const {
	SLLIC tmp;
	if (this->lli_ > sllic.lli_) {
		tmp.sign_ = this->sign_;
		if (this->sign_ == sllic.sign_) {
			tmp.lli_ = this->lli_ + sllic.lli_;
		}
		else {
			tmp.lli_ = this->lli_ - sllic.lli_;
		}
	}
	else {
		tmp.sign_ = sllic.sign_;
		if (this->sign_ == sllic.sign_) {
			tmp.lli_ = this->lli_ + sllic.lli_;
		}
		else {
			tmp.lli_ = sllic.lli_ - this->lli_;
		}
	}

	return tmp;
}
SLLIC SLLIC::operator-(const SLLIC &sllic) const {
	SLLIC tmp = sllic;
	tmp.sign_ = !tmp.sign_;
	return *this + tmp;
}
SLLIC & SLLIC::operator++() {
	SLLIC tmp("1");
	*this = *this + tmp;
	return *this;
}
SLLIC SLLIC::operator++(int x) {
	SLLIC tmp("1");
	SLLIC tmp2;
	tmp2 = *this;
	*this = *this + tmp;
	return tmp2;
}
SLLIC & SLLIC::operator--() {
	SLLIC tmp("1");
	*this = *this - tmp;
	return *this;
}
SLLIC SLLIC::operator--(int x) {
	SLLIC tmp("1");
	SLLIC tmp2;
	tmp2 = *this;
	*this = *this - tmp;
	return tmp2;
}

istream & operator>>(istream & is, SLLIC &sllic) {
	char ch[100];
	is >> ch;
	char *p = ch;
	if ((*p) == '-') {
		sllic.sign_ = 0;
		++p;
	}
	sllic.lli_ = p;
	return is;
}

ostream & operator<<(ostream & os, const SLLIC &sllic) {
	if (!sllic.sign_) {
		os << "-";
	}
	os << sllic.lli_;
	return os;
}
