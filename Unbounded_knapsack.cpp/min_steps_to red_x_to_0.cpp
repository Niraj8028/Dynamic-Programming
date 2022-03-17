#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
unordered_map<string,int>mp;

int solve(int arr[],int n,int k,int l,int r,int count){
    if(k==0){
        return count; 
    }
    if(k<0){
        return 1e6;
    }
    string key=to_string(l)+"*"+to_string(r)+"*"+to_string(k);
    if(mp.count(key)){
        return mp[key];
    }
   
    int left=solve(arr,n,k-arr[l],l+1,r,1+count);
    int right=solve(arr,n,k-arr[r],l,r-1,1+count);
    return mp[key]=min(left,right);
}

int main(){
    int n=5;
    int arr[n]={1,1,4,2,3};
    
    int k=5;
    solve(arr,n,k,0,n-1,0);
    
    return 0;
}