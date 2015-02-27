#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define mp make_pair
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(0);
	int n,m; cin >> n >> m;
	priority_queue<pair<int, pair<int,int> >, vector< pair<int, pair<int,int> >  >, greater< pair<int, pair<int,int> >  > > pq; // your sum, your first index, your second index
	pair<int, pair<int, int> > tracker[n]; // whether you still exist (your value for yes, 0 for no), your left buddy index (-1 for terminal), your right buddy index (-1 for terminal)
	int prv, cur;
	cin >> prv;
	tracker[0].first = prv;
	tracker[0].second.first = -1;
	for(int i = 1; i < n; i++){
		cin >> cur;
		//cout << "Cur is " << cur << " and pushing in " << cur + prv << endl;
		pq.push(mp(cur+prv,mp(i-1,i)));
		tracker[i-1].second.second = i;
		tracker[i].second.first = i-1;
		tracker[i].first = cur;
		prv = cur;
	}
	tracker[n-1].second.second = -1;
	int mergesLeft = n-m;
	while(mergesLeft != 0){
		pair<int, pair<int,int> > top = pq.top(); pq.pop();
		//cout << "top.first is " << top.first << endl;
		//cout << "top.second.first is " << top.second.first << endl;
		//cout << "top.second.second is " << top.second.second << endl;
		// checking if it is still valid via the tracker
		// check first index
		if(tracker[top.second.first].first == 0 || tracker[top.second.second].first == 0 || (top.first != tracker[top.second.first].first + tracker[top.second.second].first)){
			//cout << "INVALID!\n";
			continue; // invalid
		}
		// from here on it is valid!
		// so we are going to combine the numbers.
		// we'll let the new number rest on the index of the first index
		tracker[top.second.first].first = top.first; // update first with your sum
		//cout << "newly updated: tracker["<< top.second.first<<"].first is now " << tracker[top.second.first].first << endl;
		//if(tracker[top.second.second])
		tracker[top.second.second].first = 0; // second one merged, no longer exists
		// now we need to find the two buddies beside the newly merged number
		// find the left buddy first
		int pointerIndex = tracker[top.second.first].second.first;
		while(true){
			if(tracker[pointerIndex].second.first == -1 && tracker[pointerIndex].first == 0){
				// reached terminal, terminal one is gone!
				tracker[top.second.first].second.first == -1;
				break;
			}
			if(tracker[pointerIndex].first >= 1){
				// thing still exists, add it in
				tracker[top.second.first].second.first = pointerIndex;
				break;
			}
			if(tracker[pointerIndex].first == 0){
				pointerIndex = tracker[pointerIndex].second.first;
			}
		}
		// now find the right buddy
		pointerIndex = tracker[top.second.second].second.second;
		while(true){
			if(tracker[pointerIndex].first == 0 && tracker[pointerIndex].second.second == -1){
				tracker[top.second.first].second.second == -1;
				break;
			}
			if(tracker[pointerIndex].first >= 1){
				tracker[top.second.first].second.second = pointerIndex;
				break;
			}
			if(tracker[pointerIndex].first == 0){
				pointerIndex = tracker[pointerIndex].second.second;
			}
		}
		// so now we should have the correct left and right buddies 
		// we can add them into the pq
		// push the left one first
		int leftIndex = tracker[top.second.first].second.first;
		int rightIndex = tracker[top.second.first].second.second;
		if(leftIndex != -1){
			pq.push(mp(top.first + tracker[leftIndex].first, mp(leftIndex, top.second.first) ));
			//cout << "ADDING NEW ELEMENTS: from leftIndex of " << leftIndex << " to current pos of " << top.second.first << " we get a sum of " << top.first + tracker[leftIndex].first << endl;
		}
		if(rightIndex != -1){
			pq.push(mp(top.first + tracker[rightIndex].first, mp(top.second.first, rightIndex)));
			//cout << "ADDING NEW ELEMENTS: from rightIndex of " << rightIndex << " to current pos of " << top.second.first << " we get a sum of " << top.first + tracker[rightIndex].first << endl;
		}		
		mergesLeft--;
	}	
	int highest = 0;
	for(int i = 0; i < n; i++){
		//cout << "tracker[i].first is " << tracker[i].first << endl;
		highest = max(highest, tracker[i].first);	
	}
	cout << highest;
	/*
	vector<int> elements;
	int temp, old; cin >> old;
	id.push_back(true);
	elements.push_back(old);
	for(int i = 1; i < n; i++){
		cin >> temp;
		id.push_back(i);
		elements.push_back(temp);
		pq.push(mp(temp+old,mp(i-1,i)));
		old = temp;
	}
	int mergesLeft = n-m;
	while(mergesLeft != 0){
		
	}
	
	6 3
4 2 4 5 1 1
	
	
	*/
}
