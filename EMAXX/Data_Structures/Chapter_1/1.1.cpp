#include <iostream>
#include <stack>
using namespace std;

// Minimum Stack / Minimum Queue


stack<pair<int, int>> st;

void add_elem(int new_elem) {
	int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
	st.push({new_elem, new_min});
}

int remove_elem() {
	int removed_element = st.top().first;
	st.pop();
	return removed_element;
}

int find_min() {
	return st.top().second;
}

int main() {
	add_elem(10);
	add_elem(60);
	add_elem(1);
	// cout << remove_elem() << endl;

	cout << find_min() << endl;
}