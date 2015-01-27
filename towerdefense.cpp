#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 2000000000
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;
adjList al;
int main(){
	int n,e; cin >> n >> e;
	al.assign(n,vii());
	int dist[n], ways[n];
	memset(ways, 0, sizeof ways);
	for(int i = 0; i < n; i++) dist[i] = INF;
	int a,b,c;
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &a, &b, &c);
		al[a].push_back(ii(b,c));
	}
	dist[0] = 0;
	ways[0] = 1;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]) continue;
		for(int j = 0; j < (int)al[u].size(); j++){
			ii v = al[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				ways[v.first] = ways[u]%MOD;
				pq.push(ii(dist[v.first],v.first));
			} else if(dist[u] + v.second == dist[v.first]){
				ways[v.first] += ways[u]%MOD;
				ways[v.first] %= MOD;
			}
		}
	}
	cout << ways[n-1];
}
