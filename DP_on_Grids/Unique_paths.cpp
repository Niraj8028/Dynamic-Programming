#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];
int paths(int m,int n){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            
        }
    }
    return dp[m-1][n-1];
}
int main(){
    int m=4;
    int n=3;
    cout<<paths(m,n);
    
    return 0;
}