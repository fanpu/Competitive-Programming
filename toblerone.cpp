#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
int main(){
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << "lel";
	int current = 0, startIndex = 0, highestStart = 0, highestEnd = 0, highest = -INF;
	for(int i = 0; i < n; i++){
		current += a[i];
		cout << "current is " << current << endl;
		if(startIndex == -1 && a[i] >= 0){
			current = a[i];
			startIndex = i;
		}
		if(current < 0){
			startIndex = -1;
			current = 0;
		}
		if(current > highest){
			cout << "Current > highest, current is " << current << endl;
			highestStart = startIndex;
			highestEnd = i;
			highest = current;
			cout << "highestStart is now " << highestStart << endl;
			cout << "highestEnd is now " << highestEnd << endl;
		}
		
	}
	cout << "SECOND LOOP\n";
	for(int i = 0; i < startIndex; i++){
		current += a[i];
		if(current > highest){
			cout << "Current > highest, current is " << current << endl;
			highestEnd = i;
			highest = current;
			cout << "highestStart is now " << highestStart << endl;
			cout << "highestEnd is now " << highestEnd << endl;
		}
		if(current < 0) break;
	}
	cout << highest << " " << highestStart << " " << highestEnd;
	
}
/*
9
5 4 -2 1 3 5 -1 99 1

8
5 4 -2 1 3 5 -7 1

12
-120 -120 -120 1 2 3 4 5 6 -99 -999 -999
*/
