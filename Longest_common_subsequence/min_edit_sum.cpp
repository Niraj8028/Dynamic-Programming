#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int sum(string x,string y,int m,int n){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=j;
            }
            else if(x[m-1]==y[n-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }
    return dp[m][n];
}

int main(){
    string x="sunday";
    string y="saturday";
    int m=x.length();
    int n=y.length();
    cout<<sum(x,y,m,n);
    return 0;
}