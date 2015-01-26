#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> adjList;
adjList al;
int stoneArr[1000010];
int moves = 0;
int test;
int dfs(int curNode){
	int numStones = 0;
	if(al[curNode].size() == 0){
		return stoneArr[curNode] - 1;
	}
	cout << "hi2\n";
	cin >> test;
	for(int i = 0; i < (int)al[curNode].size(); i++){
		int temp = dfs(al[curNode][i]);
		moves += abs(temp);
		numStones += temp;
	}
	cout << "hi\n";
	cin >> test;
	numStones += stoneArr[curNode];
	return numStones - 1;
}

int main() {
	int n; cin >> n;
	al.assign(n+1,vi());
	int rootNode, rootStones;
	int parent, stones;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &parent, &stones);
		if(parent==-1){
			rootNode = parent;
			stoneArr[i] = stones;
			continue;
		}
		al[parent].push_back(i);
		stoneArr[i] = stones;
	}
	cout << "lel";
	cin >> n;
	for(int i = 0; i < (int)al[rootNode].size(); i++){
		moves += abs(dfs(al[rootNode][i]));
	}
	cout << moves;
	return 0;
}
