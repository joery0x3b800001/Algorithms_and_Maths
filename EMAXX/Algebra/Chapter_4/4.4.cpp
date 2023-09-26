#include <iostream>
#include <vector>
using namespace std;

// Factorial modulo p

/**
 * 
 *  The main part of the blocks it is easy to count -
 *        it's just (p - 1)!mod(p).
 *  We can compute thatprogramatically or just apply Wilson's
 *  theorem which states that (p - 1)!mod(p) = -1 for any prime p.
 *  
*/

/**
 *   We have exactly [n / p] such blocks, therefore 
*/

int factmod(int n, int p) {
	vector<int> f(p);
	f[0] = 1;
	for (int i = 1; i < p; i++)
		f[i] = f[i-1] * i % p;

	// sort(f.begin(), f.end());
	int res = 1;
	while (n > 1) {
		if ((n / p) % 2)
			res = p - res;
		res = res * f[n%p] % p;
		n /= p;
	}
	return res;
}

// Multiplicity of p
// If we want to calculate a Binomial coefficient modulo p,
// then we additionally need the multiplicity of p in n.
// i.e, the number of times p occurs in the prime factorization n.
int multiplicity_factorial(int n, int p) {
	int count = 0;
	do {
		n /= p;
		count += n;
	} while (n);
	return count;
}

int main() {
	int p, n;
	cin >> n >> p;
	cout << factmod(n, p) << endl;
	cout << multiplicity_factorial(n, p) << endl;
}