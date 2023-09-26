#include <iostream>
#include <vector>
using namespace std;


/**
 * 
 * 	Chinese Remainder Theorem
 *  		{ a = a1.mod(m1)
 * 		{ a = a1.mod(m2)
 * 		.
 * 		.
 * 		.
 * 		{ a = ak.mod(mk)
 * 
 * 		Where mi are pairwise coprime.
 *    	Where ai are given some constraints. The original form of
 * 		CRT then states that the given system of congruences
 * 		always has one and exactly one solution modulo m 
 * 	
 * 	Corollary:
 * 		A consquence of the CRT is that the equation
 * 			x = a.mod(m)
 * 		is equivalent to the system of equations
 * 			{ x = a1.mod(m1)
 * 			.
 * 			.
 * 			.
 * 			{ x = ak.mod(mk)
*/

int mod_inv(int a, int m) {
	return a <= 1 ? a : m - (long long)(m/a) * mod_inv(m % a, m) % m;
}

struct Congruence {
	long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const & congruences) {
	long long M = 1;
	for (auto const& congruence : congruences) {
		M *= congruence.m;
	}

	long long solution = 0;
	for (auto const& congruence : congruences) {
		long long a_i = congruence.a;
		long long M_i = M / congruence.m;
		long long N_i = mod_inv(M_i, congruence.m);
		solution = (solution + a_i * M_i % M * N_i) % M;
	}
	return solution;
}

// Solution for two Moduli
/**
 *  Consider a System of two equations for coprime m1, m2:
 * 	{a = a1.mod(m1)
 *    {a = a2.mod(m2)
 * 
 *  We want to find a solution for a.mod(m1.m2). Using the
 *  Eucidean extended algorithm we can find the Bézout coefficients
 *  		n1, n2 such that:
 * 			n1.m1 + n2.m2 = 1
*/

int bezout3(int oldarray[], int coeff[], int length)
{
    // the array must have at least 2 elements
    assert(length >= 2);

    // make a copy of the array
    int array[length];
    memcpy(array, oldarray, sizeof(array));

    // find the smallest non-zero element of the array
    int smallest = 0;
    for (int i = 1; i < length; i++)
    {
        if (array[i] != 0 && (array[smallest] == 0 || array[i] < array[smallest]))
            smallest = i;
    }

    // all elements must be non-negative, and at least one must be non-zero
    assert(array[smallest] > 0);

    // for every element of the array, compute the remainder when dividing by the smallest
    int changed = false;
    for (int i = 0; i < length; i++)
        if (i != smallest && array[i] != 0)
        {
            array[i] = array[i] % array[smallest];
            changed = true;
        }

    // base case: the array has only one non-zero element, which is the gcd
    if (!changed)
    {
        coeff[smallest] = 1;
        return array[smallest];
    }

    // recursively reduce the elements of the array till there's only one
    int result = bezout3(array, coeff, length);

    // update the coefficient of the smallest element
    int total = coeff[smallest];
    for (int i = 0; i < length; i++)
        if (oldarray[i] > array[i])
        {
            int q = oldarray[i] / array[smallest];
            total -= q * coeff[i];
        }
    coeff[smallest] = total;

    // return the gcd
    return result;
}

int main(void)
{
    int array[3] = { 3515, 550, 420 };
    int coeff[3] = {    0,   0,   0 };
    int length = 3;

    int result = bezout3(array, coeff, length);

    printf("gcd=%d\n", result);
    int total = 0;
    for (int i = 0; i < length; i++)
    {
        printf("%4d * %4d\n", array[i], coeff[i]);
        total += array[i] * coeff[i];
    }
    printf("total=%d\n", total);
}