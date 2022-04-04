#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int square(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++){
        dp[i][0]=0;
    }
    for(int i=0; i<=n; i++){
        dp[0][i]=0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(grid[i-1][j-1]==1){
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
            else if(grid[i-1][j-1]==0){
                dp[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
          ans=max(ans,dp[i][j]);  
        }
        
    }
    return ans;
}
int main(){
    vector<vector<int>>grid={{1,0,1,1,1},
                             {1,0,1,1,1},
                             {1,1,1,1,1},
                             {1,0,0,1,0}};
    cout<<square(grid);
    return 0;
}