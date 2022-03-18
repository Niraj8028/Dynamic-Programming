#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int longest_substring(string x,string y,int m,int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    int mx=INT_MIN;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(x[i-1]==y[i-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    mx++;
                }
                else{
                    
                    dp[i][j]=0;
                }
            }
        }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            mx=max(dp[i][j],mx);
        }
    }
    
    return mx;
}

int main(){
    string x="abefghj";
    string y="abdfcsgh";
    cout<<longest_substring(x,y,x.length(),y.length());
    return 0;
}