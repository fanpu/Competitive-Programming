#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll arr[4]; for(int i = 0; i < 4; i++) cin >> arr[i];
  ll change; cin >> change;
  // clearing 50 cents
  ll numToUse50 = change/50;
  numToUse50 = min(numToUse50, arr[3]);
  change -= numToUse50 * 50;
  ll numToUse20 = change/20;
  numToUse20 = min(numToUse20, arr[2]);
  change -= numToUse20 * 20;
  ll numToUse10 = change/10;
  numToUse10 = min(numToUse10, arr[1]);
  change -= numToUse10 * 10;
  ll numToUse5 = change/5;
  numToUse5 = min(numToUse5, arr[0]);
  change -= numToUse5 * 5;
  if(change == 10 && arr[2] - numToUse20 >= 3){
	numToUse50--;
	numToUse20 += 3;
	change += 50;
	change -= 3*20;
  }
  if(change != 0) cout << -1;
  else{
    cout << numToUse5 << " " << numToUse10 << " " << numToUse20 << " " << numToUse50 << " " << numToUse5+numToUse10+numToUse20+numToUse50;
  }
}
