#include <iostream>
#include <vector>
using namespace std;

// Euler totient function from 1 to n..
void phi_1_to_n(int n) {
	vector<int> phi(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}


// Finding the totient from 1 to n using the divisor sum property..
void phi_1_to_n_divisor(int n) {
	vector<int> phi(n + 1);
	phi[0] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = i - 1;

	for (int i = 2; i <= n; i++)
		for (int j = 2 * i; j <= n; j += i)
			phi[j] -= phi[i];
}

int main() {
	// phi_1_to_n(21);
	// phi_1_to_n_divisor(10);
}