#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	string s;
	int male = 0, female = 0;
	while(n--){
		cin >> s;
		if(s=="MEW") male++;
		if(s=="MEOW") female++;
	}
	if(male==0) cout << "OMG MEEEAHHHH!!!!\n";
	else cout << (int)(female/male);
}
