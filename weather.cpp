#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> adjList;
int main(){
  ios::sync_with_stdio(0);
  int n,d; cin >> n >> d; 
  int arr[26][26];
  memset(arr, 0, sizeof arr);
  string s;
  char day1, dayN;
  for(int i = 0; i < n-d+1; i++){
    cin >> s;
    for(int j = 1; j < s.length(); j++){
      arr[s[j-1]-'A'][s[j]-'A'] += 1;
    }
  }
  for(int k = 0; k < 26; k++){
      // for every char, check if outgoing char and incoming char is diff
    int totalOut = 0, totalIn = 0; 
    for(int j = 0; j < 26; j++){
      totalOut += arr[k][j];
      totalIn += arr[j][k];
    }
    if(totalOut > totalIn){ // more outgoing edges than incoming (assuming k to be vertex)
      day1 = k + 'A';
    } else if(totalIn > totalOut){
      dayN = k + 'A';
    }
      
  }
  cout << day1 << dayN;
}
