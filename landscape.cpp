#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
typedef pair<ll,ll> ii;
int main(){
	stack<ii> ls;
	int n, temp; ll area = 0; ii a; cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d",&temp);
		if(ls.size()==0){
			ls.push(mp(temp,i));
		} else{
			a = ls.top();
			if(temp > a.first) ls.push(mp(temp,i));
			while(temp < a.first){
				area = max(area, (i-a.second)*a.first);
				//cout << "Current area is " << area << " at i = " << i << endl;
				ls.pop(); 
				if(ls.size()==0){
					ls.push(mp(temp,i));
					break;
				}
				a = ls.top();
				if(temp > a.first){
					ls.push(mp(temp,i));
					break;
				}
				else if (temp == ls.top().first) break;
			}
		}
	}
	while(ls.size() > 0){
		a = ls.top(); ls.pop();
		area = max(area, (n-a.second)*a.first);
		//cout << "area is " << area << endl;
	}
	cout << area << endl;
}

/*

15
1 2 2 2 1 1 2 2 2 1 5 5 5 0 0
 
*/
