#include <bits/stdc++.h>

using namespace std;

int main()
{   
    freopen("input.txt","r",stdin);
    int n,k,t; cin >> n >> k >> t;
    int restriction[n+1];
    for(int i = 1; i <= n; i++) scanf("%d",&restriction[i]);
    int dp[n+1][k+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int minHeight = restriction[i];
            int maxArea = 0;
            for(int a = 0; a <= i && a < t; a++){
                minHeight = min(minHeight, restriction[i-a]);
                maxArea = max(maxArea, minHeight*(a+1) + dp[i-a][j-1]);
            }
            dp[i][j] = max(maxArea, dp[i-1][j]);
        }
        
    }
    cout << dp[n][k];
    
   return 0;
}
