#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
#define mp make_pair

bool isSorted(vector<int> u){
  bool sorted = true;
  for(int i = 1; i < (int)u.size(); i++){
    if(u[i] > u[i-1]){
		sorted = false;
		break;
	}
  }
  return sorted;
}

int main(){
  ios::sync_with_stdio(0);
  signed char memo[8][8][8][8][8][8][8][8];
  int tc; cin >> tc;
  int n;
  pair<int,int> arr[8];
  while(tc--){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> arr[i].first; arr[i].second = i;
    }
    sort(arr, arr+n);
    vi pancake;
    for(int i = 0; i < n; i++) pancake.push_back(arr[i].second);
    for(int i = n; i < 8; i++) pancake.push_back(0); 
    queue<pair<vector<int>,int> > q;
    q.push(mp(pancake,0));
    while(!q.empty()){
      vi u = q.front().first; int d = q.front().second; q.pop();
      if(memo[u[0]][u[1]][u[2]][u[3]][u[4]][u[5]][u[6]][u[7]] != 0){
	cout << memo[u[0]][u[1]][u[2]][u[3]][u[4]][u[5]][u[6]][u[7]] + d << "\n";
	break;
      } else if(isSorted(u) == true){
	cout << d << "\n";
	memo[u[0]][u[1]][u[2]][u[3]][u[4]][u[5]][u[6]][u[7]] = d;
	break;
      }
      stack<int> s;
      for(int i = 1; i < 8; i++){
	vi v;
	// i denotes the position to flip from
	for(int j = 0; j < i; j++){
	  v.push_back(u[j]); //pushing in unchanged elements
	}
	for(int j = 7; j > i; j--){ //reverse copying elements, pushing in the rightmost in first
	  v.push_back(u[j]);
	}
	q.push(mp(v,d));
      }
      
    }
  }

}
