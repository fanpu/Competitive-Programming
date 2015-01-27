#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef pair<int,int> ii;
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
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,s));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
	}
}
