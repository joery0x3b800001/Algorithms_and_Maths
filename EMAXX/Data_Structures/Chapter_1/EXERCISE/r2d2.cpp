// https://codeforces.com/problemset/problem/514/D
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>
#include<stack>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

int n, m, k, sum, START, END, mx;
long long d[100000][5], c, x, y, best[5];
stack<pair<long long, long long> > in[5];
stack<pair<long long, long long> > out[5];

void fill_out(){
	pair<long long, long long> temp;
	while(!in[0].empty()){
		for(int i = 0; i < m; i++){
			temp = in[i].top();
			in[i].pop();
			if(out[i].empty()) out[i].push(make_pair(temp.second, temp.second));
			else{
				out[i].push( make_pair(max(out[i].top().first, temp.second), temp.second) );
			}
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	
	for(int i = 0; i < n; i++){
		sum = 0;
		for(int j = 0; j < m; j++){
			cin >> d[i][j];
			c = (!in[j].empty())? in[j].top().first: 0;
			c = max(c, d[i][j]);
			in[j].push(make_pair(c, d[i][j]));
		}
		END++;
		for(int j = 0; j < m; j++){
			sum += max(in[j].top().first, (!out[j].empty())? out[j].top().first: 0);
		}
		
		//cout<<sum<<endl;
		
		if(sum <= k){
			if(END - START + 1 > mx){
				mx = END - START + 1;
				for(int j = 0; j < m; j++){
					best[j] = max(in[j].top().first, (!out[j].empty())? out[j].top().first: 0);;
				}
			}
		}
		else{
			while(sum > k and START <= END){
				if(out[0].empty()) fill_out();
				sum = 0;
				START++;
				for(int j = 0; j < m; j++){
					if(!out[j].empty()){
						out[j].pop();
						x = (out[j].empty())? 0: out[j].top().first;
						y = (in[j].empty())? 0: in[j].top().first;
						sum += max(x, y);
					}
				}
			}
			
			if(END - START + 1 > mx){
				mx = END - START + 1;
				for(int j = 0; j < m; j++){
					best[j] = max( (in[j].empty())? 0: in[j].top().first, (!out[j].empty())? out[j].top().first: 0);
				}
			}
		}
	}
	
	for(int j = 0; j < m; j++){
		cout<<best[j]<<" ";
	}	
	
	cout<<endl;
	
	return 0;
}
