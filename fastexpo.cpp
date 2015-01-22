#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m;

int fastExp(ll base, ll p){
	if(p==0) return 1;
	else if(p==1) return base;
	else{
		ll res = fastExp(base,p/2);
		res *= res;
		res %= m;
		if(p%2==1) res *= base%m;
		res %= m;
		return res;
		}
}

int main(){
	ll a,b;
	int input;
	cin >> input;
	while(input--){
		cin >> a >> b >> m;
		cout << fastExp(a,b) << "\n";
	}
	cin >> a;
}
