#include <iostream>
#include <deque>
using namespace std;

// Queue modification(method 2)
deque<pair<int,int>> q;
int cnt_added = 0;
int cnt_removed = 0;

int find_min() {
	int minimum = q.front().first;
	return minimum;
}

void add_elem(int new_element) {
	while (!q.empty() && q.back().first > new_element)
		q.pop_back();
	q.push_back({new_element, cnt_added});
	cnt_added++;
}

void remove_elem() {
	// int removed_element = 0;
	if (!q.empty() && q.front().second == cnt_removed) {
		// removed_element = q.front().first;
		q.pop_front();
	}
	cnt_removed++;
	// return removed_element;
}

int main() {
	add_elem(30);
	add_elem(10);

	cout << find_min() << endl;

	remove_elem();
	// cout << remove_elem() << endl;
	cout << find_min() << endl;
}