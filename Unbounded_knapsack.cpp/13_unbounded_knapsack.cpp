#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1000][1000];

int unboundedKnapsack(int val[],int wt[],int w,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<w; j++){
            if(i==0){
                dp[0][j]=0;
            }
            if(j==0){
                dp[i][0]=0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(wt[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;
    cout<<unboundedKnapsack(val,wt,w,n);
    
    return 0;
}