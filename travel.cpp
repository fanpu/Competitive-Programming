#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define mp make_pair
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;
adjList al;
int main(){
	ios_base::sync_with_stdio(0);
	int n,m; cin >> n >> m;
	al.assign(n+1,vii());
	int u,v,l;
	for(int i = 0; i < m; i++){
		cin >> u >> v >> l;
		al[u].push_back(ii(v,l));
		al[v].push_back(ii(u,l));
	}
	int best[n+1], secondBest[n+1];
	for(int i = 0; i <= n; i++){
		best[i] = INF;
		secondBest[i] = INF;
	}
	
}
