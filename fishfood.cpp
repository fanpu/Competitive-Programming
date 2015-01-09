//#include "fishfood.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#define mp make_pair
#define INF 2000000000
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> adjList;
adjList al;

int fishfood(int N, int E, int K, int A[], int B[], int T[]) {
	al.assign(N,vii());
	for(int i = 0; i < E; i++){
		al[A[i]].push_back(mp(B[i],T[i]));
		al[B[i]].push_back(mp(A[i],T[i]));
	}
	int dist[N]; //dist from source
	for(int i = 0; i < N; i++) dist[i] = INF;
	dist[0] = 0;
	priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0,0)); //weight, label
	while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if(d > dist[u]) continue;
		for(int j = 0; j < (int)al[u].size(); j++){
			ii v = al[u][j];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first], v.first));
			}
		}
	}
	sort(dist,dist+N);
	if(dist[K-1] == INF) return -1;
	else return dist[K-1];
}

int main() {
	int N, E, K, A[500000], B[500000], T[500000];
    scanf("%d%d%d", &N, &E, &K);
    for ( int i = 0; i < E; i++ ) scanf("%d%d%d", &A[i], &B[i], &T[i]);
    printf("%d\n", fishfood(N, E, K, A, B, T));
    return 0;
}
