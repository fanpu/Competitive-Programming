#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> adjList;
adjList al;
int main(){
	int n, m; cin >> n >> m;
	int a,b,l;
	al.assign(n+1,vii());
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &l);
		al[a].push_back(ii(b,l));
		al[b].push_back(ii(a,l));
	}
	vi dist(n+1, INF); dist[1] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,1));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]) continue;
		for(int j = 0; j < (int)al[u].size(); j++){
			ii v = al[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
	int oldShortest = dist[n];
	int longest = 0;
	for(int a = 1; a <= n; a++){
		for(int b = 0; b < (int)al[a].size(); b++){
			//if(dist[a] > oldShortest || dist[b] > oldShortest) continue;
			al[a][b].second *= 2;
			vi newdist(n+1, INF); newdist[1] = 0;
			priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,1));
			while(!pq.empty()){
				ii front = pq.top(); pq.pop();
				int d = front.first, u = front.second;
				if(d > newdist[u]) continue;
				for(int j = 0; j < (int)al[u].size(); j++){
					ii v = al[u][j];
					if(newdist[u] + v.second < newdist[v.first]){
						newdist[v.first] = newdist[u] + v.second;
						pq.push(ii(newdist[v.first],v.first));
					}
				}
			}
			
			al[a][b].second /= 2;
			longest = max(longest, newdist[n] - oldShortest);
		}	
	}
	cout << longest;
}

/*

5 7
2 1 5
1 3 1
3 2 8
3 5 7
3 4 3
2 4 7
4 5 2

*/
