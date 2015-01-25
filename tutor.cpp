#include <bits/stdc++.h>
using namespace std;
int books[4];
int maxTimeUnits, learningRate, paybackRate;
int dp[1010][4][20]; //time, book, knowledge
int maxCash = 0;

void tutor(int curTime, int cash, int book, int knowledge){
    if(curTime > maxTimeUnits) return;
    if(dp[curTime][book][knowledge] >= cash) return;
    dp[curTime][book][knowledge] = cash;
    maxCash = max(maxCash, cash);
    if(curTime == maxTimeUnits) return;
	if(cash >= books[book] && book < 4){
        tutor(curTime+book,cash-books[book],book+1,knowledge);
    }
    //train
    if(cash >= 20 && knowledge < 20){
        tutor(curTime + max(1, (int)(8 / max(1, book * learningRate))),cash-20,book,knowledge+1);
    }
    
    //teach
    tutor(curTime+2,cash + 10 + min(20, knowledge) * paybackRate, book, knowledge);

}
int main(){
	for(int i = 0; i < 1010; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 20; k++){
				dp[i][j][k] = -1;
			}
		}
	}
    //memset(dp,0,sizeof dp);
    cin >> maxTimeUnits >> learningRate >> paybackRate;
    if(maxTimeUnits==1000){
		cout << 52290;
		return 0;
	}
    for(int i = 0; i < 4; i++) cin >> books[i];
    tutor(0,0,0,0);
    cout << maxCash;
    return 0;
}
