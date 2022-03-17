#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1000][1000];

int no_of_ways(int arr[],int n,int k){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(i==0){
               dp[i][j]=0;
            }
            if(j==0){
               dp[i][j]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][k];
}
int main(){
    int n=3;
    int arr[n]={1,2,5};
    int k=5;
    cout<<no_of_ways(arr,n,k);
    return 0;
}