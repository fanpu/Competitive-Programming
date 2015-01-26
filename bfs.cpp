// inside int main() -- no recursion
vi d(V, INF); d[s] = 0;
queue<int> q; q.push(s); // start from source

while(!q.empty()){
	int u = q.front(); q.pop();	// queue: layer by layer
	for(int j = 0; j < (int)AdjList[u].size(); j++){ // for each neighbor of u
		ii v = AdjList[u][j];
		if(d[v.first] == INF){ // if v.first is unvisited + reachable
			d[v.first] = d[u] + 1;	// make d[v.first] != INF to flag it
			q.push(v.first);	// enqueue v.first for the next iteration
		}
	}
}
