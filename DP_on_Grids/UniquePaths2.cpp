#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int paths(vector<vector<int>>&grid){
    int m=grid.size();
    int n=grid[0].size();
    bool flag=false;
    for(int i=0; i<n; i++){
        if(flag || grid[0][i]==1){
            flag=true;
            dp[i][0]=0;
        }
        else{
            dp[i][0]=1;
        }
    }
    flag=true;
    for(int j=0; j<m; j++){
        if(flag || grid[j][0]==1){
            flag=true;
            dp[0][j]=0;
        }
        else{
            dp[0][j]=1;
        }
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(grid[i][j]==1){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }        
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int>>grid={{0,0,0,0},
                             {1,0,1,0},
                             {0,0,0,0}};
    cout<<paths(grid);
    return 0;
}