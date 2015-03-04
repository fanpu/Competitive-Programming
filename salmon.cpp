#include<bits/stdc++.h>
using namespace std;
int main(){
/*
Name			Price	Salmon Sashimi Required
Salmon Sashimi	2		1
Salmon Maki		7		2
Premium Bento	60		17
Yu Sheng		588		179
CNY Gift Box	2888	630

dp: find the best possible value for each number of salmon
cycle thru each item, and see if it would result in a better combi if used
*/
	int salmonRequired[] = {1,2,17,179,630};
	int price[] = {2,7,60,588,2888};
	int n; cin >> n;
	int bestVal[n+1]; memset(bestVal, 0, sizeof bestVal);
	bestVal[0] = 0;
	int combiChosen[5]; memset(combiChosen, 0, sizeof combiChosen);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 5; j++){
			if(i-price[j] >= 0 && )
		}
	}
	
}
