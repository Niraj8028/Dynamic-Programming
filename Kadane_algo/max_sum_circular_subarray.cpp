#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int maxSum(int arr[],int n){
    int mx=INT_MIN;
    int mxt=0;
    int total=0;
    int mn=INT_MAX;
    int mnt=0;
    
    for(int i=0; i<n; i++){
        total=total+arr[i];
        mxt=mxt+arr[i];
        if(mxt>mx){
            mx=mxt;
        }
        
        if(mxt<0){
            mxt=0;
        }
        
        int mnt=mnt+arr[i];
        if(mn>mnt){
            mn=mnt;
        }
        if(mnt>0){
            mnt=0;
        }
        
    }
    if(total==mn){
        return mx;
    }
    int ans=total-(mn);
    return ans;
}
int main(){
    int arr[]={-1,-2,-3,-2,-6};
    int n=5;
    cout<<maxSum(arr,n);
    return 0;
}