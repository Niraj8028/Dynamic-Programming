#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];
int mcm(int arr[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(mn>temp){
            mn=temp;
        }
    }
    dp[i][j]=mn;
    return dp[i][j];
}


int main(){
    int arr[]={40,20,30,10,30};
    int n=5;
    memset(dp,-1,sizeof(dp));
    cout<<mcm(arr,1,n-1);   
    return 0;
}