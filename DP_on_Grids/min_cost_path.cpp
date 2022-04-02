#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];
int cost(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    dp[0][0]=grid[0][0];

    for(int i=1; i<n; i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1; i<m; i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>>grid={{1,3,5},
                             {2,1,2},
                             {4,3,1}};
                             
    cout<<cost(grid);                    

    return 0;
}