#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int n,k,b;
vector<vector<int> > bars;
vector<vector<int> > memo;

ll dfs(int thisNum, int barPos, int curNumPos){
	if(barPos >= b-1) return 1;
	if(memo[barPos][curNumPos] != -1){
		return memo[barPos][curNumPos];
	}
	ll times = 0;
	for(int i = 0; i < bars[barPos+1].size(); i++){
		// binarysearch the range
		
		if(abs(bars[barPos+1][i] - thisNum) <= k){
			if(barPos+1 == b-1)
				times += 1;
			else
				times += dfs(bars[barPos+1][i], barPos+1, i);
			times %= MOD;
		}
	}
	return memo[barPos][curNumPos] = times;
}

int main(){
	freopen("input2.in","r",stdin);
	//ios::sync_with_stdio(0);
	cin >> n >> k >> b;
	bars.assign(b,vector<int>());
	int barNum,pitch;
	for(int i = 0; i < n; i++){
		cin >> barNum >> pitch;		
		bars[barNum-1].push_back(pitch);
	}	
	memo.assign(b,vector<int>());
	for(int i = 0; i < b; i++){
		memo[i].assign(bars[i].size(),-1);
		sort(bars[i].begin(),bars[i].end());
	}
	ll sum = 0;
	for(int i = 0; i < bars[0].size(); i++){ // i: element in each bar
		for(int j = 0; j < bars[1].size(); j++){ // j: next element in each bar
			if(abs(bars[0][i] - bars[1][j]) <= k){		
				if(memo[1][j]!=-1){
					sum += memo[1][j];
					continue;
				}
				sum += dfs(bars[1][j],1,j) % MOD;
				sum %= MOD;
			}
		}
	}
	
	for(int i = 0; i < b; i++){
		for(int j = 0; j < bars[i].size(); j++){
			cout << memo[i][j] << " ";
		} cout << endl;
	}
	cout << sum;
}



/*
12 2 5
1 1
1 3
1 5
2 2
2 4
2 7
3 3
3 8
4 5
4 10
5 7
5 8
*/
