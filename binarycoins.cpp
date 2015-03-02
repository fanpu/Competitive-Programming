#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int main(){
	ull b; cin >> b;
	int count = 0;
	for(ull i = 0; i < 64; i++){
		if(b & (ull)((ull)1 << i))count++;
	}
	cout << count;
}
