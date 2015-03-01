#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define INF 2000000000
typedef vector<int> vi;
int a[] = {-1,0,0,1}; // y axis
int b[] = {0,-1,1,0}; // x axis

int main(){
	ios::sync_with_stdio(0);
	int n; cin >> n;
	char arr[n][n];
	queue<pair<int,int> > q;
	pair<int,int> start, end;
	int dist[n][n];
	vector<pair<int,int> > tsp;
	int foodCount = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
      			if(arr[i][j] == 'F'){
			  tsp.push_back(mp(i,j));
			  arr[i][j] = foodCount + '0';
			  foodCount++;
			}
			else if(arr[i][j] == 'S'){
			  start.first = i; start.second = j;\
			}
			else if(arr[i][j] == 'B'){
			  end.first = i; end.second = j;
			}
		}
	}
	for(int i = 0; i < tsp.size(); i++){
	  cout << "First: " << tsp[i].first << " second: " << tsp[i].second << endl;
	}
	int tspMatrix[tsp.size()+2][tsp.size()+2];
	for(int i = 0; i < tsp.size() + 2; i++) for(int j = 0; j < tsp.size() + 2; j++) tspMatrix[i][j] = INF;
	for(int x = 0; x < tsp.size(); x++){
	  // for every iteration, make tsp[i] the starting point
	  // find dist from this food to all other foods
	  q = queue<pair<int,int> >();
	  q.push(mp(tsp[x].first,tsp[x].second));
	  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = INF;
	  dist[tsp[x].first][tsp[x].second] = 0;
	  while(!q.empty()){
	    pair<int,int> u = q.front(); q.pop();
	    for(int i = 0; i < 4; i++){
	      if(u.first + a[i] >= 0 && u.first + a[i] < n && u.second + b[i] >= 0 && u.second
	       + b[i] < n && arr[u.first+a[i]][u.second+b[i]] != 'X' && dist[u.first+a[i]][u.second+b[i]] == INF){
		dist[u.first+a[i]][u.second+b[i]] = dist[u.first][u.second] + 1;
		if(arr[u.first+a[i]][u.second+b[i]] >= '0' && arr[u.first+a[i]][u.second+b[i]] <= '9'){
		  tspMatrix[x][arr[u.first+a[i]][u.second+b[i]]-'0'] = dist[u.first][u.second] + 1;
		  tspMatrix[arr[u.first+a[i]][u.second+b[i]] - '0'][x] = dist[u.first][u.second] + 1;
		}
		q.push(mp(u.first+a[i],u.second+b[i]));
	      }
	    }
	  }
	}
	for(int x = 0; x < 1; x++){
	  // find dist between start and all elements
	  q = queue<pair<int,int> >();
	  q.push(mp(start.first,start.second));
	  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = INF;
	  dist[start.first][start.second] = 0;
	  while(!q.empty()){
	    pair<int,int> u = q.front(); q.pop();
	    for(int i = 0; i < 4; i++){
	      if(u.first + a[i] >= 0 && u.first + a[i] < n && u.second + b[i] >= 0 && u.second
	       + b[i] < n && arr[u.first+a[i]][u.second+b[i]] != 'X' && dist[u.first+a[i]][u.second+b[i]] == INF){
		dist[u.first+a[i]][u.second+b[i]] = dist[u.first][u.second] + 1;
		if(arr[u.first+a[i]][u.second+b[i]] >= '0' && arr[u.first+a[i]][u.second+b[i]] <= '9'){
		  tspMatrix[tsp.size()][arr[u.first+a[i]][u.second+b[i]] - '0'] = dist[u.first][u.second] + 1;
		  tspMatrix[arr[u.first+a[i]][u.second+b[i]] - '0'][tsp.size()] = dist[u.first][u.second] + 1;
		}
		q.push(mp(u.first+a[i],u.second+b[i]));
	      }
	    }
	  }
	}

	for(int x = 0; x < 1; x++){
	  // find dist between bed and all elements
	  q = queue<pair<int,int> >();
	  q.push(mp(end.first,end.second));
	  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) dist[i][j] = INF;
	  dist[end.first][end.second] = 0;
	  while(!q.empty()){
	    pair<int,int> u = q.front(); q.pop();
	    for(int i = 0; i < 4; i++){
	      if(u.first + a[i] >= 0 && u.first + a[i] < n && u.second + b[i] >= 0 && u.second
	       + b[i] < n && arr[u.first+a[i]][u.second+b[i]] != 'X' && dist[u.first+a[i]][u.second+b[i]] == INF){
		dist[u.first+a[i]][u.second+b[i]] = dist[u.first][u.second] + 1;
		if(arr[u.first+a[i]][u.second+b[i]] >= '0' && arr[u.first+a[i]][u.second+b[i]] <= '9'){
		  tspMatrix[tsp.size()+ 1][arr[u.first+a[i]][u.second+b[i]] - '0'] = dist[u.first][u.second] + 1;
		  tspMatrix[arr[u.first+a[i]][u.second+b[i]] - '0'][tsp.size() + 1] = dist[u.first][u.second] + 1;
		}
		q.push(mp(u.first+a[i],u.second+b[i]));
	      }
	    }
	  }
	}
	// tsp matrix constructed
	// check if its possible

	for(int i = 0; i < tsp.size() + 2; i++){
	  for(int j = 0; j < tsp.size() + 2; j++){
	    if(tspMatrix[i][j] != INF) cout << tspMatrix[i][j] << " ";
	    else cout << "x" << " ";
	  } cout << endl;
	}
}
