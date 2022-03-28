#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int MCM(int arr[],int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                dp[i][j]=0;
            }
        }
    }
    for(int L=2; L<n-1; L++){
        for(int l=1; l<(n-L); l++){
            int r=l+L-1;
            dp[l][r]=INT_MAX;
            for(int k=l; k<r; k++){
                int ans=dp[l][k]+dp[k+1][r]+(arr[l-1]*arr[k]*arr[r]);
                dp[l][r]=min(dp[l][r],ans);
            }
        }
    }
    return dp[1][4];
}
int main(){
    int n=5;
    int arr[n]={4,2,3,1,3};
    cout<<MCM(arr,n);
    return 0;
}