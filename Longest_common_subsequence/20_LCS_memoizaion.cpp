#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int LCS(string x,string y,int m,int n){
    if(m==0 || n==0){
        return dp[m][n]=0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    else{
        if(x[m-1]==y[n-1]){
            return dp[m][n]=1+LCS(x,y,m-1,n-1);
        }
        else{
            return dp[m][n]=max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
        }
    }
    return dp[m][n];

}

int main(){
    string x="abefghj";
    string y="abdfcsgh";
    memset(dp,-1,sizeof(dp));
    cout<<LCS(x,y,x.length(),y.length());
    
    return 0;
}