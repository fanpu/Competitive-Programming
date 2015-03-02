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
  pair<int,int> day1, dayN;
  day1.first = day1.second = dayN.first = dayN.second = -1;
  for(int i = 0; i < n-d+1; i++){
    cin >> s;
    for(int j = 1; j < s.length(); j++){
      arr[s[j-1]-'A'][s[j]-'A'] += 1;
      //cout << s[j-1] << s[j] << endl;
    }
  }
  for(int k = 0; k < 26; k++){
      // for every char, check if outgoing char and incoming char is diff
    int totalOut = 0, totalIn = 0; 
    for(int j = 0; j < 26; j++){
      totalOut += arr[k][j];
      totalIn += arr[j][k];
    }
    cout << "For " << char(k+'A') << ": totalOut is " << totalOut << ", totalIn is " << totalIn << endl;
    if(totalOut > totalIn){ // more outgoing edges than incoming (assuming k to be vertex)
      //cout << "day1 possible: " << (char)(k+'A') << endl;
      if(day1.first == -1) day1.first = k;
      else day1.second = k;
    } else if(totalIn > totalOut){
      //cout << "dayN possible: " << (char)(k+'A') << endl;
      if(dayN.first == -1) dayN.first = k;
      else dayN.second = k;
    }
      
  }
  cout << char(day1.first + 'A') << " " << char(day1.second + 'A')<< endl;
  cout << char(dayN.first + 'A') << " " << char(dayN.second + 'A')<< endl;
  // we have our day1 and dayN, now for some edge comparison
  if(day1.second == -1) cout << char(day1.first + 'A');
  else if(arr[day1.first][day1.second] > arr[day1.second][day1.first]) cout << char(day1.first + 'A');
  else cout << char(day1.second + 'A');
  if(dayN.second == -1) cout << char(dayN.first + 'A');
  else if(arr[dayN.first][dayN.second] < arr[dayN.second][dayN.first]) cout << char(dayN.first + 'A');
  else cout << char(dayN.second + 'A');
}
