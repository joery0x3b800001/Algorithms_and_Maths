#include <iostream>
using namespace std;

// Submask enumeration
/**
 *  Enumerating all submasks of a given masks
 * 	- Given a bitmask m, you want to efficiently iterate thorugh all
 * 	  of its submasks, that is, masks s in which only bits that
 *      were included in mask are set.
*/


void iterate_submasks(int n) {
	for (int m = 0; m < (1 << n); ++m) {
		for (int s=m; s; s=(s-1)&m) {
			cout << m << " : " << s << endl;
		}
		cout << endl << endl;
	}
}

int main() {
	int m; cin >> m;
	// int s = m, count = 0;
	// // while (s > 0) {
	// // 	s = (s - 1) & m;
	// // 	cout << s << endl;
	// // 	++count;
	// // }
	// cout << count << endl;
	// cout << m << endl;
	iterate_submasks(m);
}