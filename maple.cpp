#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	string arr[n];
	map<int,string> tour;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int temp;
	for(int i = 0; i < n; i++){
		scanf("%d",&temp);
		tour[temp] = arr[i];
	}
	map<int, string>::iterator it;
	for (it = tour.begin(); it != tour.end(); ++it) {
		cout << it->second << "\n";
	}
}
