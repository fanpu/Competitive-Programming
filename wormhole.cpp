#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi planets;
int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	int shortest[n];
	planets.assign(n,vi());
	for(int i = 0; i < n; i++) shortest[i] = INF;
	int wormholes; cin >> wormholes;
	int a,b;
	for(int i = 0; i < wormholes; i++){
		cin >> a >> b;
		planets[a].push_back(b);
	}
	int curTime = 0;
	for(int i = 0; i < n; i++){
		curTime = min(shortest[i], curTime);
		for(int j = 0; j < planets[i].size(); j++){
			shortest[planets[i][j]] = min(shortest[planets[i][j]], curTime + 1);
		}
		curTime = min(shortest[i], curTime);
		shortest[i] = min(shortest[i], curTime);
		curTime += 1;
	}
	cout << shortest[n-1];
}
