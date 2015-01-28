#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
typedef pair<ll,ll> ii;
int main(){
	freopen("input.txt","r",stdin);
	stack<ii> ls;
	int n, temp; ll area = 0; ii a; cin >> n;
	int i = 0;
	while(cin >> temp){
		if(ls.size()==0){
			ls.push(mp(temp,i));
		} else{
			a = ls.top();
			if(temp > a.first){
				ls.push(mp(temp,i));
				continue;
			} else if (temp == a.first) continue;
			while(temp < a.first){
				//cout << "temp is " << temp << endl;
				//cout << "a.first is " << a.first << endl;
				area = max(area, (i-a.second)*a.first);
				//cout << "Current area is " << area << " at i = " << i << endl;
				ls.pop(); 
				//cout << "Popped an element " << a.first << endl;
				if(ls.size()==0){
					ls.push(mp(temp,i));
					//cout << "lel\n";
					break;
				}
				a = ls.top();
				if(temp > a.first){
					//cout << "hi\n";
					ls.push(mp(temp,i));
					break;
				}
				else if (temp == a.first) break;
			}
		}
		i++;
	}
	while(ls.size() > 0){
		a = ls.top(); ls.pop();
		area = max(area, (n-a.second)*a.first);
		//cout << "area is " << area << " with height " << a.first << endl;
	}
	cout << area << endl;
}

/*

25
1 2 2 2 1 1 2 2 2 1 5 5 5 0 0 1 2 3 4 5 6 7 8 9 10
 
*/
