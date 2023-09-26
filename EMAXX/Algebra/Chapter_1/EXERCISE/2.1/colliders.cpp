// https://codeforces.com/problemset/problem/154/B
// Less time and space complexity
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define maxn 100007

using namespace std;

set<int> s;

int prime[maxn];
int mark[maxn];
int vis[maxn];
int a[maxn];
int cnt = 0;

void find_prime(int n)
{
	for (int i=2; i<=n; i++)
	{
		if (vis[i] == 0)
		{
			prime[cnt++] = i;
			for (int j=i; j<=n; j+=i)
				vis[j] = 1;
		}
	}
}

int is_exit(int x)
{
	int tmp = x;
	for (int i=0; i<cnt && prime[i]*prime[i] <= tmp; i++)
	{
		if (x % prime[i] == 0)
		{
			if (s.find(prime[i]) != s.end())
				return prime[i];

			while (x % prime[i] == 0)
				x /= prime[i];
		}
	}
	if (x > 1)
	{
		if (s.find(x) != s.end())
			return x;
	}
	return 0;
}

void add(int x)
{
	int tmp = x;
	for (int i=0; i<cnt && prime[i]*prime[i] <= x; i++)
	{
		if (x % prime[i] == 0)
		{
			a[prime[i]] = tmp;
			s.insert(prime[i]);
		}

		while (x % prime[i] == 0)
			x /= prime[i];
	}
	if (x > 1)
	{
		a[x] = tmp;
		s.insert(x);
	}
}

void del(int x)
{
	for (int i=0; i<cnt && prime[i]*prime[i] <= x; i++)
	{
		if (x % prime[i] == 0)
		{
			s.erase(prime[i]);
			a[prime[i]] = 0;
		}
		while (x % prime[i] == 0)
			x /= prime[i];
	}

	if (x > 1)
	{
		s.erase(x);
		a[x] = 0;
	}
}

int main()
{
	int n, m;
	find_prime(maxn);

	scanf("%d%d", &n, &m);

	char ch[2];
	int num;
	for (int i=0; i<m; i++)
	{
		scanf("%s %d", ch, &num);

		if (ch[0] == '+')
		{
			if (mark[num] == 1)
				printf("Already on\n");
			else
			{
				int tmp = is_exit(num);
				if (tmp == 0)
				{
					printf("Success\n");
					add(num);
					mark[num] = 1;
				}
				else printf("Conflict with %d\n", a[tmp]);
			}
		} else if (ch[0] == '-')
		{
			if (mark[num] == 0)
				printf("Already off\n");
			else
			{
				del(num);
				mark[num] = 0;
				printf("Success\n");
			}
		}
	}
	return 0;
}