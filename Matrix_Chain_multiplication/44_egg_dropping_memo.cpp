#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int solve(int f,int e){
    if(e==1){
        return f;
    }
    if(f==1 || f==0){
        return f;
    }
    if(dp[f][e]!=-1){
        return dp[f][e];
    }
    int mn=INT_MAX;
    for(int x=1; x<=f; x++){
        int m,n;
        if(dp[x-1][e-1]!=-1){
            m=dp[x-1][e-1];
        }
        else{
            m=solve(x-1,e-1);
        }
        if(dp[f-x][e]!=-1){
            n=dp[f-x][e];
        }
        else{
            n=solve(f-x,e);
        }
        int temp=1+max(m,n);
        mn=min(mn,temp);
    }
    return dp[f][e]=mn;
}

int main(){
    int e=3;
    int f=5;
    memset(dp,-1,sizeof(dp));
    cout<<solve(f,e);
    return 0;
}