#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<iii> viii;
typedef vector<viii> adjList;
#define INF 2000000000
#define mp make_pair

int a[] = {-1,0,0,1};
int b[] = {0,-1,1,0};

int main(){
	int n; cin >> n;
	char room[n][n];
	int dist[n][n];
	queue<ii> q;
	ii start,end;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = INF;
			cin >> room[i][j];
			if(room[i][j]=='X'){
				q.push(ii(i,j));
				dist[i][j]=0;
			} else if(room[i][j]=='S'){
				start.first = i, start.second = j;
			} else if(room[i][j]=='E'){
				end.first = i, end.second = j;
			}
		}
	}
	while(!q.empty()){
		ii u = q.front(); q.pop();
		int y = u.first, x = u.second;
		for(int i = 0; i < 4; i++){
			if(y+a[i] >= 0 && y+a[i] < n && x+b[i] >= 0 && x+b[i] < n){
				if(dist[y+a[i]][x+b[i]] == INF){
					dist[y+a[i]][x+b[i]] = dist[y][x] + 1;
					//cout << y+a[i] << " " << x+b[i] << " " << dist[y+a[i]][x+b[i]] << endl;
					q.push(ii(y+a[i],x+b[i]));
				}				
			}
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dist[i][j] << " ";
		} cout << endl;
	}*/
	
	int arr[n][n][4]; //0: from top, 1: from bottom, 2: from left, 3: from right
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(room[i][j]=='X') arr[i][j][0] = 0;
			else(arr[i][j][0]=arr[i-1][j][0]+1);
		}
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < n; j++){
			if(room[i][j]=='X') arr[i][j][1] = 0;
			else(arr[i][j][1]=arr[i+1][j][1]+1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(room[i][j]=='X') arr[i][j][2] = 0;
			else(arr[i][j][2]=arr[i][j-1][2]+1);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = n-1; j >= 0; j--){
			if(room[i][j]=='X') arr[i][j][3] = 0;
			else(arr[i][j][3]=arr[i][j+1][3]+1);
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << arr[i][j][0] << " " << arr[i][j][1] << " " << arr[i][j][2] << " " << arr[i][j][3] << endl; 
		}
	}*/
	adjList al;
	al.assign(n*n,viii());
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(room[i][j] == 'X') continue;
			for(int k = 0; k < 4; k++){
				if(i+a[k] >= 0 && i+a[k] < n && j+b[k] >= 0 && j+b[k] < n && room[i+a[k]][j+b[k]] != 'X'){
					al[i*j+j].push_back(iii(ii(i+a[k],j+b[k]),1));
				}
			}
			al[i*j+j].push_back(iii(ii(i-arr[i][j][0]+1,j),dist[i][j]));
			al[i*j+j].push_back(iii(ii(i+arr[i][j][1]-1,j),dist[i][j]));
			al[i*j+j].push_back(iii(ii(i,j-arr[i][j][2]+1),dist[i][j]));
			al[i*j+j].push_back(iii(ii(i,j+arr[i][j][3]-1),dist[i][j]));
		}
	}
	int distance[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			distance[i][j] = INF;
		}
	}
	distance[start.first][start.second] = 0;
	priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > >pq;
	pq.push(mp(0,mp(start.first,start.second)));
	while(!pq.empty()){
		pair<int,pair<int,int> > front = pq.top(); pq.pop();
		int d = front.first, u1 = front.second.first, u2 = front.second.second;
		if(d > distance[u1][u2]) continue;
		//cout << al[u1*u2+u2].size() << endl;
		for(int j = 0; j < (int)al[u1*u2+u2].size(); j++){
			iii v = al[u1*u2+u2][j];
			//cout << "v.second is " << v.second << endl;
			if(distance[u1][u2] + v.second < distance[v.first.first][v.first.second]){
				distance[v.first.first][v.first.second] = distance[u1][u2] + v.second;
				pq.push(mp(distance[v.first.first][v.first.second],mp(v.first.first,v.first.second)));
			}
		}
	}
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(distance[i][j] == INF) cout << "X" << " ";
			else cout << distance[i][j] << " ";
		} cout << endl;
	}*/
	cout << distance[end.first][end.second];
}
