#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll* x, ll* y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    ll x1, y1;
    ll g = gcd(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1-y1*(a/b);
    return g;
}

int main(){

    while(1){

        ll n, m, a, k;
        cin >> n >> m >> a >> k;

        if(n==0 && m==0 && a==0 && k==0){
            break;
        } 

        ll x, y;
        ll g = gcd(a, -m, &x, &y);

        ll dif = n-k;

        if(dif%g!=0){
            cout << "Impossible\n";
            continue;
        }
        
        if(g < 0){
            x = -x, y = -y, g = -g;
	}

        x = x*(dif/g);
        y = y*(dif/g);

        ll d = m/g;

        if(x <= 0){
            ll mult = (abs(x)/d)+1;
            x += d*mult;
        }else{
            ll mult = (x-1)/d;
            x -= d*mult;
        }

        cout << k+a*x << endl;

    }

    return 0;
}