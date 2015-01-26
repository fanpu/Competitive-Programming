#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define INF 2000000000
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> adjList;
adjList al;


int main(){
	int n,e; cin >> n >> e;
	ll arr[n+1][n+1];
	int v1, v2, c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			arr[i][j] = INF;
			if(i==j) arr[i][j] = 0;
		}
	}
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &v1, &v2, &c);
		arr[v1][v2] = c;
		arr[v2][v1] = c;
	}
	ll small = INF;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				arr[i][k] = min(arr[i][j], arr[
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			//use as nodes
			small = min(small, arr[1][i] + arr[2][i] + arr[3][j] + arr[4][j] + arr[i][j]);
			cout << "Small is " << small << endl;
			small = min(small, arr[1][i] + arr[3][i] + arr[2][j] + arr[4][j] + arr[i][j]);
			cout << "Small is " << small << endl;
			small = min(small, arr[1][i] + arr[4][i] + arr[2][j] + arr[3][j] + arr[i][j]);
			cout << "Small is " << small << endl;
		}
	}
	cout << small;
}
