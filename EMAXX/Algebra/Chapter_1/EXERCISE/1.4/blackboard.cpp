// https://codeforces.com/problemset/problem/217/B
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define INT_INF 0x7f7f7f7f

const int limit = 1e5;

int n,r;
int res;
char str[limit];
char s[limit];
void check(int t, int b)
{
	int len = 0;
	while (t!=b && t>=0 && b>=0)
	{
		if (t>b)
		{
			s[len++] = 'T';
			t -= b;
		}
		else
		{
			s[len++]='B';
			b -= t;
		}
	}

	if (len != n-1 || t != 1)
		return;

	s[len] = 'T';
	int k = 0;
	for (int i=0;i<len;++i)
		if(s[i] == s[i+1])
			k++;
	if (k<res)
	{
		res = k;
		for (int i=0;i<=len;++i)
			str[i] = s[len-i];
		str[len+1] = '\0';
	}
}

int main()
{
	cin >> n >> r;
	res = INT_INF;

	for (int i=1;i<=r;i++) {
		check(i, r);
		// check(r, i);
	}

	if (res == INT_INF)
		cout << "IMPOSSIBLE\n";
	else
		cout << res << endl << str << endl;
	return 0;
}