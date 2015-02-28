	#include<bits/stdc++.h>
	using namespace std;
	int main(){
		ios::sync_with_stdio(0);
		int n; double l; cin >> l >> n;
		double arr[n];
		pair<double,double> people[n];
		for(int i = 0; i < n; i++){
			cin >> people[i].first >> people[i].second;
		}
		sort(people, people + n);
		for(int i = 0; i < n; i++){
			arr[i] = -(l/people[i].second + people[i].first);
		}
		vector<double> lis;
		lis.push_back(arr[0]);
		for(int i = 1; i < n; i++){
			if(arr[i] > lis[lis.size()-1]){
				lis.push_back(arr[i]);
			}
			else{
				lis[lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin()] = arr[i];
			}
		}

		cout << lis.size();
	}
