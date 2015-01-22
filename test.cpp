#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll _sieve_size;
bitset<10000010> bs;
//vi primes;
int primecount = 0;
int primenum;
void sieve(ll n){
	_sieve_size = n + 1;
	bs.set();
	bs[0]=bs[1]=0;
	for(ll i=2;i<=_sieve_size;i++){
		if(primecount==primenum){ cout << i-1 << endl;return;}
		if(bs[i]){
			for(ll j=i*i;j<=_sieve_size;j+=i){
				bs[j] = 0;
			}
			primecount++;
		}
	}
}
int main(){
	cin >> primenum;
	sieve(10000000);
}
