#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int t[1001][1001];

int subsetCount(int arr[],int n, int sum){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                t[0][j]=0;
            }
            if(j=0){
                t[i][0]=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i]<j){
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    int n=6;
    int arr[n]={2,3,5,6,8,10};
    int sum=10;
    cout<<subsetCount(arr,n,sum);

    
    return 0;
}