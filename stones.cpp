#include <iostream>
using namespace std;
#define mp make_pair
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> adjList;
adjList al;
int stoneArr[1000010];
int moves = 0;
int dfs(int curNode){
	
	int numStones = 0;
	if(al[curNode].size() == 0){
		return stoneArr[curNode] - 1;
	}
	for(int i = 0; i < (int)al[curNode].size(); i++){
		int temp = dfs(al[curNode][i].first);
		moves += abs(temp);
		numStones += temp;
	}
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
			rootStones = stones;
			continue;
		}
		al[parent].push_back(i));
		stoneArr[i] = stones;
		}
	// your code goes here
	return 0;
}
