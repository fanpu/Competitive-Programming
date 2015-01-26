int VISITED = 1, UNVISITED = -1;
vi dfs_num;	// global variable, initially all values are set to UNVISITED

void dfs(int u){
	dfs_num[u] = VISITED;
}
