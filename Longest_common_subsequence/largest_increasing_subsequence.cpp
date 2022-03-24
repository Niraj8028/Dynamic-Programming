#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001];

int LIS(int arr[],int m){
    dp[0]=1;
    int mx=0;
    int large=0;
    for(int i=1; i<m; i++){
        for(int j=0; j<i; j++){
            
            if(arr[i]>arr[j]){
                if(dp[j]>mx){
                    mx=dp[j];
                }
            }
        }
        dp[i]=mx+1;
        if(dp[i]>large){
            large=dp[i];
        }
    }
    return large;
}
int main(){
    int n=10;
    int arr[n]={10,22,9,33,31,50,41,60,80,1};
    cout<<LIS(arr,n);
    
    return 0;
}