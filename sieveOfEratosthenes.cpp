#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef vector<int> vi;
ll sieveSize;
bitset<10000010> bs;
vi primes; // list of primes

void sieve(ll upperbound){	// create list of primes in [0..upperbound]
	sieveSize = upperbound + 1;	// add 1 to include upperbound
	bs.set();	// set all bits to 1
	bs[0] = bs[1] = 0;	// except index 0 and 1
	for(ll i = 2; i <= sieveSize; i++) if (bs[i]){
		// cross out multiples of i starting from i * i
		for(ll j = i * i; j <= sieveSize; j += i) bs[j] = 0;
		primes.push_back(i);
}}
	
bool isPrime(ll N){	// a good enough deterministic prime tester
	if(N <= sieveSize) return bs[N];
	for(int i = 0; i < (int)primes.size(); i++)
		if(N % primes[i] == 0) return false;
	return true;
}	// only works for N <= (last prime in vi "primes")^2

int main(){
	sieve(10000000);
	printf("%d\n", isPrime(2147483647));	// return true
	printf("%d\n", isPrime(136117223861));	// return false
}
