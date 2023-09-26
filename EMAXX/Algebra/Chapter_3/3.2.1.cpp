#include <iostream>
using namespace std;

// Number of Divisors
long long numberOfDivisors(long long num) {
	long long total = 1;
	for (int i = 2; (long long)i * i <= num; i++) {
		if (num % i == 0) {
			int e = 0;
			do {
				e++;
				num /= i;
			} while (num % i == 0);
			total *= e + 1;
		}
	}
	if (num > 1) {
		total *= 2;
	}
	return total;
}


// Sum of Divisors
long long SumOfDivisors(long long num) {
	long long total = 1;

	for (int i = 2; (long long)i * i <= num; i++) {
		if (num % i == 0) {
			int e = 0;
			do {
				e++;
				num /= i;
			} while (num % i == 0);

			long long sum = 0, pow = 1;
			do {
				sum += pow;
				pow *= i;
			} while (e-- > 0);
			total *= sum;
		}
	}
	if (num > 1) {
		total *= (1 + num);
	}
	return total;
}

int main() {
	int num;
	cin >> num;

	cout << SumOfDivisors(num) << '\n';
	cout << numberOfDivisors(num) << '\n';
}