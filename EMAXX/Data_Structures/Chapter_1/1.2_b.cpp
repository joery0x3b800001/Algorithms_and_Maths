#include <iostream>
#include <stack>
using namespace std;


// Queue modification(method 3)
stack<pair<int,int>> s1, s2;

int find_min() {
	int minimum = 0;
	if (s1.empty() || s2.empty())
		minimum = s1.empty() ? s2.top().second : s1.top().second;
	else
		minimum = min(s1.top().second, s2.top().second);
	return minimum;
}

void add_elem(int new_element) {
	int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
	s1.push({new_element, minimum});
}

int remove_elem() {
	if (s2.empty()) {
		while (!s1.empty()) {
			int element = s1.top().first;
			s1.pop();
			int minimum = s2.empty() ? element : min(element, s2.top().second);
			s2.push({element, minimum});
		}
	}

	int remove_element = s2.top().first;
	s2.pop();
	return remove_element;
}

int main() {
	add_elem(3);
	add_elem(2);
	add_elem(1);
	add_elem(4);

	cout << find_min() << endl;
	cout << remove_elem() << endl;
	cout << remove_elem() << endl;
	cout << remove_elem() << endl;
	cout << find_min() << endl;
}