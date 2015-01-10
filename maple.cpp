#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	pair<int,char[21]> arr[n];
	for(int i = 0; i < n; i++) cin >> arr[i].second;
	for(int i = 0; i < n; i++){
	    cin >> arr[i].first;
	}
	sort(arr,arr+n);
	for(int i = 0; i < n; i++) cout << arr[i].second  << "\n";
}
