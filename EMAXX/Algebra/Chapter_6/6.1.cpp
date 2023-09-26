#include <iostream>
using namespace std;
// Binary manipulation


// Useful tricks
// Set / flip / clear a bit

/**
 *
 * 
 *  (1 << x) is a number with only the x-th bit set.
 *  ~(1 << x) is a number with all bits set except the x-th bit.
 *  
*/

void set_flip_clear() {
	int n = 10;
	int x = 2; // xth bit position

	cout << (n | (1 << x)) << endl; // set the x-th bit in the number n.
	cout << (n ^ (1 << x)) << endl; // flip the x-th bit in the number n.
	cout << (n & ~(1 << x)) << endl; // clears the x-th bit in the number n.
}

// Check of a bit is set
/**
 *  The value of the x-th bit can be checked by shifting the
 *  number x positions to the right, so that the x-th bit
 *  is at the unit place, which we can extract it by performing
 *  a bitwise & with 1.
*/
bool is_set(unsigned int number, int x) {
	return (number >> x) & 1;
}

// Check if an integer is a power of 2
bool isPowerOfTwo(unsigned int n) {
	return n && !(n & (n - 1));
}

// Clear the most-right set bit
unsigned int clear_set_msb(unsigned int n) {
	return n & (n - 1);
}

//
int countSetBits(int n) {
	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

// Additional tricks
void additional_tricks() {
	int n = 0b00110111;
	cout << (n & (n + 1)) << '\n'; // clears all trailing ones
	// n = (n & (n + 1));
	cout << (n | (n + 1)) << '\n'; // sets the last cleared bit
	cout << (n & -n) << '\n'; // extracts the last set bits
}

int main() {
	unsigned int unsigned_number = 13;
	assert(unsigned_number == 0b1101);

	int positive_signed_number = 13;
	assert(positive_signed_number == 0b1101);

	int negative_signed_number = -13;
	// assert(negative_signed_number == 0b1111'1111'1111'1111'1111'1111'1111'0011);

	// cout << (5 >> 2) << endl;
	// cout << (5 << 3) << endl;
	// set_flip_clear();

	unsigned int d = 5;
	// cout << isPowerOfTwo(32) << endl;

	// d = clear_set_msb(d);

	// cout << d << endl;

	// additional_tricks();
	cout << countSetBits(10) << endl;
	cout << __builtin_popcount(10) << endl; // returns the numbers of set bits
	cout << __builtin_ffs(10) << endl; // finds the index of the first(most right) set bit.
	cout << __builtin_clz(10) << endl; // the count of leading zeros.
	cout << __builtin_ctz(10) << endl; // the count of trailing zeros.
}