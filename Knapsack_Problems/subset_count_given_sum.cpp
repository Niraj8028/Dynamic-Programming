#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int t[1000][1000];

int subsetcount(int arr[],int n,int sum){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                t[0][j]=0;
            }
            if(j==0){
                t[i][0]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]>j){
                t[i][j]=t[i-1][j];
            }
            else if(arr[i-1]<=j){
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][sum];
}

int main(){
    int n=3;
    int arr[n]={1,2,1};
    int sum=3;
    cout<<subsetcount(arr,n,sum);
    
    
    return 0;
}