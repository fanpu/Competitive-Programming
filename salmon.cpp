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
	ios::sync_with_stdio(0);
	int salmonRequired[] = {1,2,17,179,809};
	int price[] = {2,7,60,588,2888};
	int n; cin >> n;
	int bestVal[n+1]; memset(bestVal, 0, sizeof bestVal);
	bestVal[0] = 0; // best price u can get for a given number of sashimi
	int combiChosen[n+1][5]; memset(combiChosen, 0, sizeof combiChosen);
	for(int i = 0; i < 5; i++) combiChosen[0][i] = 0;
	for(int i = 1; i <= n; i++){ // i: number of sashimi
		for(int j = 0; j < 5; j++){
			// if you can get a better price by adding a piece of new food item and subtracting the amount of sashimi required
			if((i-salmonRequired[j]) >= 0 && bestVal[i-salmonRequired[j]] + price[j] > bestVal[i]
			&& combiChosen[i-salmonRequired[j]][j] < 1023){
				bestVal[i] = bestVal[i-salmonRequired[j]] + price[j];
				// update table
				for(int k = 0; k < 5; k++) combiChosen[i][k] = combiChosen[i-salmonRequired[j]][k];
				combiChosen[i][j] += 1;
			}
			bestVal[i] = max(bestVal[i], bestVal[i-1]);
		}
	}
	cout << bestVal[n];
}
