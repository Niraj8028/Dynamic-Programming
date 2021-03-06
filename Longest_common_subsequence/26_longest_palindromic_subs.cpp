#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int LPS(string x,string y,int m ,int n){
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
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];
}

int main(){
    string x="agbcba";
    string y=x;
    reverse(y.begin(),y.end());
    cout<<y;

    cout<<LPS(x,y,x.length(),y.length());
    
    return 0;
}
