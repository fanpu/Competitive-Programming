#include "fishfood.h"
#include <cstdio>
#include <iostream>
using namespace std;


int main() {
	int N, E, K, A[500000], B[500000], T[500000];
    scanf("%d%d%d", &N, &E, &K);
    for ( int i = 0; i < E; i++ ) scanf("%d%d%d", &A[i], &B[i], &T[i]);
    printf("%d\n", fishfood(N, E, K, A, B, T));
    return 0;
}
