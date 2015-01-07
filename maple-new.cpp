#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	pair<int,string> arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i].second;
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i].first);
	}
	sort(arr,arr+n);
	for(int i = 0; i < n; i++) cout << arr[i].second  << "\n";
}

