#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
bool t[1001][1001];

int minDiff(int arr[],int n,int range){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=range; j++){
            if(i==0){
                t[0][j]=false;
            }
            if(j==0){
                t[i][0]=true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=range; j++){
            if(arr[i]<j){
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    vector<int>v;
    for(int i=0; i<=range/2; i++){
        if(t[n][i]==true){
            v.push_back(i);
        }
    }
    int mn=INT_MAX;
    for(int i=0; i<v.size(); i++){
        mn=min(mn,range-2*v[i]);
    }
    return mn;
}

int main(){
    int n=4;
    int arr[n]={1,4,11,8};
    int sum=0;
    for(int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    cout<<minDiff(arr,n,sum);
    return 0;
}