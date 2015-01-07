#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n,b; cin >> n >> b;
	pair<pair<ll,ll>,ll> airport[n];
	for(int i = 0; i < n; i++){
		cin >> airport[i].first.second >> airport[i].first.first; //first.first: takeoff, first.second: landing (inverted),second: order
		airport[i].second = i;
	}
	sort(airport,airport+n);
	int accepted[n];
	memset(accepted,0,sizeof accepted);
	priority_queue<ll> pq;
	for(int i = 0; i < b; i++) pq.push(0);
	for(int i = 0; i < n; i++){
		ll earliestEnd = -pq.top(); //job ending earliest
		ll arrivalTime = airport[i].first.second;
		if(arrivalTime >= earliestEnd){ //can i land this based on sorted earliest takeoff time? eg land after or during prev takeoff
			pq.pop();
			pq.push(-airport[i].first.first);
			accepted[airport[i].second] = 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(accepted[i]) printf("APPROVED\n");
		else printf("REJECTED\n");
	}
	return 0;
}
/*
7 2
0 4
3 9
5 6
6 8
6 10
9 14
11 13
*/
