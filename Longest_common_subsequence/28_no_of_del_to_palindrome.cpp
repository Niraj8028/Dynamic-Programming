#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int LCS(string x,string y,int m){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            
            if(x[i-1]==y[j-1]){
                 dp[i][j]=1+dp[i-1][j-1];
            } 
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
    return dp[m][m];

}
int main(){
    string x="agbcba";
    string y=x;
    reverse(y.begin(),y.end());
    int lcs=LCS(x,y,x.length());
    int ans=x.length()-lcs;
    cout<<ans;
    return 0;
}