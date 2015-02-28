#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000

int main(){
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector<int> peaks, valleys;
	int arr[n+1];
	for(int i = 1; i <= n; i++) cin >> arr[i];
	arr[0] = arr[1];
	int prvNum = arr[0], prvPrvNum = arr[0], temp;

	int plateau = 0; //0: NA, 1: peak, 2: valley
	for(int i = 0; i <= n; i++){
		temp = arr[i];
		if(temp < prvNum && prvNum > prvPrvNum){/*cout << "x " << prvNum << " " << i << endl;*/ peaks.push_back(prvNum);}
		else if(temp > prvNum && prvPrvNum > prvNum){/*cout << "y " << prvNum << " " << i << endl;*/ valleys.push_back(prvNum);}
		else if(prvPrvNum < prvNum && prvNum == temp){
			plateau = 1;
		} else if(prvNum < prvPrvNum && prvNum == temp){
			plateau = 2;
		}
		else if(plateau != 0){
			if(plateau == 1){
				if(temp < prvNum){ //plateau complete
					peaks.push_back(prvNum);
					plateau = 0;
				} else if(temp > prvNum){ //plateau failed
					plateau = 0;
				}
			} else if(plateau == 2){
				if(temp > prvNum){
					valleys.push_back(prvNum);
					plateau = 0;
				} else if(temp < prvNum){
					plateau = 0;
				}
			}
		}
		prvPrvNum = prvNum;
		prvNum = temp;
	}
	//handle edge cases
	if(arr[1] > arr[2]){/*cout << "a" << endl;*/ peaks.push_back(arr[0]);}
	//if(arr[1] < arr[2]) valleys.push_back(arr[0]);
	if(arr[n] > arr[n-1]){/*cout << "b" << endl;*/ peaks.push_back(arr[n]);}
	//if(arr[n] < arr[n-1]) valleys.push_back(arr[n]);
	sort(peaks.begin(), peaks.end(), greater<int>());
	sort(valleys.begin(), valleys.end(), greater<int>());
	int maxIsland = 0, curIsland = 0;
	int j = 0; //index of valleys
	/*
	cout << "Peaks: " << peaks.size() << endl;
	for(int i = 0; i < (int)peaks.size(); i++){
		cout << peaks[i] << " ";
	} cout << endl;
	cout << "Valleys: " << valleys.size() << endl;
	for(int i = 0; i < (int)valleys.size(); i++){
		cout << valleys[i] << " ";
	} cout << endl;
	*/
	for(int i = 0; i < (int)peaks.size(); i++){
		curIsland++;
		while(valleys[j] >= peaks[i]){
			j++;
			curIsland--;
			//cout << "valleys[" << j << "] is " << valleys[j] << endl;
			//cout << "peaks[" << i << "] is " << peaks[i] << endl;

		}
		maxIsland = max(maxIsland, curIsland);
	}
	//cout << maxIsland << endl;
	if(maxIsland == 0 && arr[0] == arr[n]) maxIsland++;
	cout << maxIsland << endl;
}

/*

7
5
6
1
3
2
9
8

*/
