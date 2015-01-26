#include <iostream>
using namespace std;
#define mp make_pair
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> adjList;
adjList al;
int stoneArr[1000010];

int dfs(int curNode){
	int moves = 0;
	if(al[curNode].size() == 0){
		return stoneArr[curNode]
	}
	for(int i = 0; i < al[curNode].size(); i++){
		dfs(al[curNode][i].first);
	}
}

int main() {
	int n; cin >> n;
	al.assign(n+1,vi());
	int rootNode;
	int parent, stones;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &parent, &stones);
		al[parent].push_back(i));
		stoneArr[i] = stones;
		if(parent==-1) rootNode = parent;
	}
	// your code goes here
	return 0;
}
