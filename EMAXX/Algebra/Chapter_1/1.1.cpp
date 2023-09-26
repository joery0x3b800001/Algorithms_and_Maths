// Links at the end of page

// Binary Exponentiation
#include <iostream>
#include <vector>
const long long maxn = 100007;

using namespace std;

/*
 *
 *s
 * a^n =  {
 *				1, 				n == 0
 *				(a^n/2)^2,  	if n > 0 and n even
 *				(a^n-1/2)^2    if n > 0 and n odd
 *			 }
 *
 *
 *
*/

// Binary exponentiation recursive
long long binpow(long long a, long long b) {
	if (b == 0)
		return 1;
	long long res = binpow(a, b / 2);
	if (b % 2)
		return res * res * a;
	else
		return res * res;
}

// Binary exponentiation iterative
long long binpowIter(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

// Modular multiplication
long long binpowMod(long long a, long long b, long long m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1; // b >>= 1 % (m-1) if the m is primeds
	}
	return res;
}

// Binary multiplication
uint64_t prod_binary(const uint64_t x, const uint64_t y, const uint64_t m)
{
	if (y <= 1)
		return y ? x : 0;
	uint64_t res = prod_binary(x,y >> 1,m);
	res = sum(res,res,m);
	if (y & 1)
		res = sum(res,x,m);
	return res;
}

// Effective computation of Fibonacci numbers
// Compute n-th fibonacci number using 2n*2n matrix
struct matrix {
	long long mat[2][2];
	matrix friend operator*(const matrix& a, const matrix& b) {
		matrix c;
		for (int i=0; i<2; i++) {
			for (int j=0; j<2; j++) {
				c.mat[i][j] = 0;
				for (int k=0; k<2; k++) {
					c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
				}
			}
		}
		return c;
	}
};

matrix matpow(matrix base, long long n) {
	matrix ans { {
		{1, 0},
		{0, 1}
	}};

	while (n) {
		if (n&1)
			ans = ans*base;
		base = base*base;
		n >>= 1;
	}
	return ans;
}

long long fib(int n) {
	matrix base {{
		{1, 1},
		{1, 0}
	}};

	return matpow(base, n).mat[0][1];
}

// Applying permutation k times
vector<int> applyPermutation(vector<int> sequence, vector<int> permutation) {
	vector<int> newSequence(sequence.size());
	for (int i=0; i<sequence.size(); i++) {
		newSequence[i] = sequence[permutation[i]];
	}
	return newSequence;
}

vector<int> permute(vector<int> sequence, vector<int> permutation, long long b) {
	while (b > 0) {
		if (b & 1) {
			sequence = applyPermutation(sequence, permutation);
		}
		permutation = applyPermutation(permutation, permutation);
		b >>= 1;
	}
	return sequence;
} 

int main() {
	// int n,p; cin >> n >> p;
	// cout << binpow(n, p) << '\n';
	// cout << binpowIter(n, p) << '\n';
	// cout << binpowMod(n, p, maxn) << '\n';

	// for (int i=0; i<10; i++) {
	// 	cout << fib(i) << ' ';
	// }

	int k=5;
	for (int i=0; i<(k<<1); i++) {
		for (auto x : permute({1,2,3,4,5}, {1,2,3,4,5}, i)) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}



// https://codeforces.com/blog/entry/96759
// https://codeforces.com/blog/entry/78873
