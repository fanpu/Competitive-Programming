#include<bits/stdc++.h>
using namespace std;

bool compareFirstBackSecondFront(string first, string second){
	//cout << "compareFirstBackSecondFront with " << first << " and " << second << endl;
	bool linked = true;
	for(int i = 1; i < (int)first.size(); i++){
		//cout << "first[i] is " << first[i] << " and second[i-1] is " << second[i-1] << endl;
		if(first[i] != second[i-1]){
			linked = false;
			break;
		}
	}
	//cout << "The result is " << linked << endl;
	return linked;
}
bool compareSecondBackFirstFront(string first, string second){
	//cout << "compareSecondBackFirstFront with " << first << " and " << second << endl;
	bool linked = true;
	for(int i = 1; i < second.size(); i++){
		//cout << "second[i] is " << second[i] << " and first[i-1] is " << first[i-1] << endl;
		if(second[i] != first[i-1]){
			linked = false;
			break;
		}
	}
	//cout << "The result is " << linked << endl;
	return linked;
}
int main(){
	ios::sync_with_stdio(0);
	int n,d; cin >> n >> d;
	pair<string, pair<int,int> > s[n-d+1]; //second.first: incoming edge, second.second: outgoing edge
	for(int i = 0; i < n-d+1; i++){
			cin >> s[i].first;
			s[i].second.first = 0, s[i].second.second = 0;
	}
	for(int i = 0; i < n-d+1; i++){
		for(int j = 0; j < n-d+1; j++){
			if(i==j) continue;
			// we are only interested in updating s[i]
			if(compareFirstBackSecondFront(s[i].first,s[j].first)==true){
				s[i].second.second += 1;
			}
			else if(compareSecondBackFirstFront(s[i].first,s[j].first)==true){
				s[i].second.first += 1;
			}
		}
	}
	char day1, dayN;
	for(int i = 0; i < n-d+1; i++){
		//cout << s[i].first << " " << s[i].second.first << " " << s[i].second.second << endl;
		if(s[i].second.second > s[i].second.first) day1 = s[i].first[0];
		if(s[i].second.first > s[i].second.second) dayN = s[i].first[s[i].first.size()-1];
	}
	cout << day1 << dayN;
}
