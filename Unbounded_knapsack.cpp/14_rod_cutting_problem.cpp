#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];


int maxProfit(int len[],int price[],int length,int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<length; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=length; j++){
            if(len[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
            }
            else if(len[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][length];
}
int main(){
    int n=4;
    int len[4]={1,2,3,4};
    int price[4]={2,3,5,7};
    int length=4;
    cout<<maxProfit(len,price,length,n);
    return 0;
}