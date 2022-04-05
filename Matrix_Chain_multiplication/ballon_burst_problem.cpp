#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];
int score(int arr[],int n){
    for(int k=1; k<=n-2; k++){
        for(int left=1; left<n-k; left++){
           int right=left+k-1;
           for(int i=left; i<=right; i++){
               dp[left][right]=max(dp[left][right],arr[left-1]*arr[i]*arr[right+1]+arr[left]*arr[i-1]+arr[right]*arr[i+1]);
           }
        }
    }   
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[1][4];

}
int main(){
    int arr[]={1,1,2,3,4,1};
    int n=6;
    memset(dp,0,sizeof(dp));
    cout<<score(arr,n);
    return 0;
}