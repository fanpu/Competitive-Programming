#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	int h,n; cin >> h >> n;
	int hay[n];
	for(int i = 0; i < n; i++) cin >> hay[i];
	// for each weight, find the best amount of hay possible
	int best[2][h+1];
	for(int i = 0; i <= h; i++){
		best[0][i] = 0;
		best[1][i] = 0;
	}
	// knapsack
	int pointer = 1;
	for(int i = 0; i < n; i++){ // i: index of hay
	  for(int j = 0; j <= h; j++) { // j: index of weight
	    best[pointer][j] = max(best[pointer][j], best[1-pointer][j]);
	    if(j-hay[i] >= 0 && best[1-pointer][j-hay[i]] + hay[i] > best[pointer][j]){
	      best[pointer][j] = best[1-pointer][j-hay[i]] + hay[i];
	    }
	  }
	  pointer = 1 - pointer;
	  for(int j = 0; j <= h; j++) best[pointer][j] = 0;
	}
	cout << best[1-pointer][h];
}
