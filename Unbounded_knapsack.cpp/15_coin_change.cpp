#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1000][1000];

int noOfCoins(int arr[],int n,int k){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j==0){
                dp[0][j]=0;
            }
            else if(i==0){
                dp[i][0]=INT_MAX;
            }
            else if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=min(1+dp[i][j-arr[i-1]],dp[i-1][j]);
                
            }
        }
    }
    cout<<dp[n][k];
}

int main(){
    int n=3;
    int arr[n]={1,2,5};
    int k=11;
    cout<<noOfCoins(arr,n,k);
    
    return 0;
}