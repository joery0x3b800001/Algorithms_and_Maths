#include <iostream>
#include <deque>
using namespace std;

// Queue modification(method 1)
deque<int> q;

int find_min() {
	int minimum = q.front();
	return minimum;
}

void add_elem(int new_element) {
	while (!q.empty() && q.back() > new_element)
		q.pop_back();
	q.push_back(new_element);
}

int remove_element(int remove_elem) {
	// int remove_elem = q.front();
	if (!q.empty() && q.front() == remove_elem)
		q.pop_front();
	return remove_elem;
}

int main() {
	add_elem(10);
	add_elem(20);
	add_elem(30);
	add_elem(50);
	cout << remove_element(10) << endl;
	cout << remove_element(30) << endl;

	cout << find_min() << endl;
}