#include <bits/stdc++.h>
#include <vector>

using namespace std;
#define mp make_pair
#define INF 2000000000
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;
typedef vector<int> vi;
adjList al;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
	// N: number of chambers
	// M: number of corridors
	// R: corridor array
	// L: time require to run thru corridor
	// K: num of exit
	// P: exit chambers array
	al.assign(N,vii());
	vector<int> exitChamber;
	for(int i = 0; i < K; i++){
		exitChamber.push_back(P[i]);
	}
	for(int i = 0; i < M; i++){
		al[R[i][0]].push_back(mp(R[i][1],L[i]));
	}
	ii initial;
	initial.first = initial.second = INF;
	vii dist(N,initial); dist[0].first = dist[0].second = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,0));
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(dist[u].second != INF) continue;
		//if( d > dist[u]) continue;
		for(int j = 0; j < (int)al[u].size(); j++){
			ii v = al[u][j];
			if(dist[v.first].first == INF){
				dist[v.first].first = dist[u].first + v.second;
				continue;
			} else if (dist[v.first].second == INF){
				int high = max(dist[v.first].first, dist[u].first + v.second);
				int low = min(dist[v.first].first, dist[u].first + v.second);
				dist[v.first].first = high;
				dist[v.first].second = low;
				pq.push(ii(dist[v.first].second,v.first));
				continue;
			} else if (dist[u].first + v.second < dist[v.first].second){
				if (dist[u].first + v.second < dist[v.first].first){
					dist[v.first].second = dist[v.first].first;
					dist[v.first].first = dist[u].first + v.second;
				} else{
					dist[v.first].second = dist[u].first + v.second;
				}
				pq.push(ii(dist[v.first].second,v.first));
			
			}
		}
	}
	int maxTime = 0;
	for(int i = 0; i < K; i++){
		maxTime = max(maxTime, dist[lower_bound(dist.begin(), dist.end(), mp(P[i],0)) - dist.begin()].second);
	}
	return maxTime;
}

int main(){
	int n,m,k; cin >> n >> m >> k;
	int arr[n][2];
	for(int i = 0; i < n; i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	int l[m];
	for(int i = 0; i < m; i++){
		cin >> l[i];
	}
	int p[k];
	for(int i = 0; i < k; i++){
		cin >> p[i];
	}
	cout << "hi";
	cout << travel_plan(n, m, arr, l, k, p);
}
