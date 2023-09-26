#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int64_t a, int64_t b) {
  return (b == 0) ? a : gcd(b, a%b);
}

int64_t lcm(int a, int b) {
  return 1LL * a * b / gcd(a, b);
}

int main(){
  int n, k;
  scanf("%d%d",&n,&k);
  int c;
  int trail = 1;
  for(int i=0;i<n;++i){
    scanf("%d",&c);
    trail = gcd(k, lcm(trail, c));
  }
  if (trail == k) printf("Yes\n");
  else printf("No\n");
  return 0;
}