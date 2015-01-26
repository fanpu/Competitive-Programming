#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 2000000000
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;
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
	vi dist(N, INF); dist[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0,0));
	while(!pq.empty()){
	}
	return N;
}

int main(){
}


