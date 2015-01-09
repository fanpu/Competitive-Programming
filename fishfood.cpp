#include "fishfood.h"
#include <cstdio>
#include <iostream>
#define mp make_pair
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
	return 0;
}
