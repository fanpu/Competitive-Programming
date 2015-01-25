#include<utility>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
#define INF 2000000000

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

bool comp(pair<int,ii> lhs, pair<int,ii> rhs){
     if(lhs.second.first < rhs.second.first) return true;
     else return false;
}

class UnionFind{
      private: vi p, rank;
      public:
               UnionFind(int N){
                             rank.assign(N,0); p.assign(N,0);
                             for(int i = 0; i < N; i++) p[i] = i;              
               }      
               int findSet(int i){
                   return (p[i] == i) ? i : (p[i] = findSet(p[i]));
               }
               bool isSameSet(int i, int j){
                    return findSet(i) == findSet(j);
               }
               void unionSet(int i, int j){
                    if(!isSameSet(i,j)){  
                        int x = findSet(i), y = findSet(j);
                        if(rank[x] > rank[y]) p[y] = x;
                        else{
                             p[x] = y;
                             if(rank[x] == rank[y]) rank[y]++;
                        }                                                                                              
                    }
               }
};

vector<pair<int, ii> > edgeList;
typedef vector<ii> vii;
typedef vector<vii> adjList;
adjList minEdge; //v1, v2, quality

int main(){
    int v,e,q; cin >> v >> e >> q;
    int v1, v2, quality;
    for(int i = 0; i < e; i++){
            scanf("%d %d %d", &v1, &v2, &quality);
            edgeList.push_back(mp(quality,mp(v1,v2)));
    }
    minEdge.assign(v+1,vii());
    sort(edgeList.begin(),edgeList.end(),greater<pair<int,ii> >());
    int mstCost;
    UnionFind UF(v+1);
    for(int i = 0; i < e; i++){
            pair<int, ii> front = edgeList[i];
            if(!UF.isSameSet(front.second.first, front.second.second)){
				//cout << "Connecting edge " << front.second.first << " with " << front.second.second << " of a cost " << front.first << endl;
				minEdge[front.second.first].push_back(mp(front.second.second,front.first));
				minEdge[front.second.second].push_back(mp(front.second.first,front.first));
				//mstCost = front.first;
				UF.unionSet(front.second.first, front.second.second);
            } 
    }
    vi dist(v+1, 0); dist[1] = INF;
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(INT_MAX,1));
    /*
    for(int i = 0; i < minEdge.size(); i++){
		for(int j = 0; j < minEdge[i].size(); j++){
			ii front = minEdge[i][j];
			cout << "At node " << i << ", my neighbour is node " << front.first << " with a weight of "<< front.second << endl;
		}
	}*/
    while(!pq.empty()){
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		//if ( d < dist[u]) continue;
		for(int j = 0; j < (int) minEdge[u].size(); j++){
			ii v = minEdge[u][j];
			if(min(dist[u], v.second) > dist[v.first]){
				dist[v.first] = min(dist[u], v.second);
				pq.push(ii(dist[v.first],v.first));
			}
		}
	}
	//for(int i = 1; i <= v; i++) cout << "dist[ " << i << "] is " << dist[i] << endl;
	int temp;
	for(int i = 0; i < q; i++){
            scanf("%d",&temp);
			printf("%d\n",dist[temp]);
    }
                                            
}
/*

4 4 2
1 2 10
1 3 30
2 4 20
3 4 5
3
4

*/
