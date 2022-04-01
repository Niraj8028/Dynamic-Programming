#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int maxSum(int arr[],int n){
    if(n==0){
        return 0;
    }
    int sum[n];
    for(int i=0; i<n; i++){
        sum[i]=arr[i];
    }
    for(int i=1; i<n;i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] && sum[i]<sum[j]+arr[i]){
                sum[i]=sum[j]+arr[i];
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans,sum[i]);
    }
    return ans;
}

int main(){
    int arr[]={1,100,3,2,6};
    int n=5;
    cout<<maxSum(arr,n);
    return 0;
}