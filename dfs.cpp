int VISITED = 1, UNVISITED = -1;
vi dfs_num;	// global variable, initially all values are set to UNVISITED

void dfs(int u){
	dfs_num[u] = VISITED;
	for(int j = 0; j < (int)AdjList[u].size(); j++){
			ii v = AdjList[u][j];	// v is a (neighbor, weight) pair
			if(dfs_num[v.first] == UNVISITED)	// important check to avoid cycle
				dfs(v.first);
	}	// for simple graph traversal, we ignore the weight stored at v.second
}
