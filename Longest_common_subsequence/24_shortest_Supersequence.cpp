#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int shortestSupersequence(string x,string y,int m,int n){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string x="AGGTAB";
    string y="GXTXAYB";
    int m=x.size();
    int n=y.size();
    int LCS=shortestSupersequence(x,y,m,n);
    int ans=(m+n)-LCS;
    cout<<ans;
    
    return 0;
}