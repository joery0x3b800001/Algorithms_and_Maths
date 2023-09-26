#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// Arbitrary-Precision Arithmetic

typedef vector<int> lnum;

const int base = 1000*1000*1000;

// Input large numbers as vector<int>
lnum input(string s) {
	lnum a;
	for (int i = (int)s.length(); i > 0; i -= 9)
		if (i < 9)
			a.push_back(atoi(s.substr(0, i).c_str()));
		else
			a.push_back(atoi(s.substr(i-9, 9).c_str()));

	while (a.size() > 1 && a.back() == 0) // delete leading zeros.
	a.pop_back();

	return a;
}

// Addition
// Increment long integer a by b and store result in a
lnum addition(lnum a, lnum b) {
	int carry = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || carry; ++i) {
		if (i == a.size())
			a.push_back(0);
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= base;
		if (carry) a[i] -= base;
	}
	return a;
}

// Subtraction
// Decrement long integer a by b(a >= b) and store result in a
lnum subtraction(lnum a, lnum b) {
	int carry = 0;
	for (size_t i = 0; i < b.size() || carry; ++i) {
		a[i] -= carry + (i < b.size() ? b[i] : 0);
		carry = a[i] < 0;
		if (carry) a[i] += base;
	}

	while (a.size() > 1 && a.back() == 0)
		a.pop_back();

	return a;
}

// Multiplication
// Multiply short integer a by short integer b(b < base) and
// store result in a.
lnum multiplication(lnum a, lnum b) {
	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
		if (i == a.size())
		   a.push_back (0);
		long long cur = carry + a[i] * 1ll * b[i];
			a[i] = int (cur % base);
			carry = int (cur / base);
	}

	while (a.size() > 1 && a.back() == 0)
	    a.pop_back();

	return a;
}

// Multilplication by long integer
// Multiply long integers a and b and store result in c
lnum multiplication2(lnum a, lnum b) {
	lnum c(a.size()+b.size());
	for (size_t i = 0; i < a.size(); ++i) { 
		for (int j = 0, carry = 0; j < (int)b.size() || carry; ++j) {
			long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
			c[i+j] = int( cur % base );
			carry = int( cur / base );
		}
	}

	while (c.size() > 1 && c.back() == 0)
		c.pop_back();

	return c;
}

// Division by short integer
// Divide long integer by short integer b(b < base), store
// integer result in a and remainder in carry.
lnum division(lnum a, lnum b) {
	int carry = 0;
	for (int i = (int)a.size()-1; i>=0; --i) {
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int( cur / b[i] );
		carry = int( cur % b[i] );
	}

	while (a.size() > 1 && a.back() == 0)
		a.pop_back();

	return a;
}

void print(lnum a) {
	printf("%d", a.empty() ? 0 : a.back());
	for (int i = (int)a.size()-2; i>=0; --i)
		printf("%09d", a[i]);
}

int main() {
	string s;
	
	cin >> s;
	lnum a = input(s);

	cin >> s;
	lnum b = input(s);

	lnum result = multiplication2(a, b);;

	// for (int i=(int)strlen(s); i>0; i-=9) {
	// 	s[i] = 0;
	// 	a.push_back(atoi(i>=9 ? s+i-9 : s));
	// }

	print(result);
}