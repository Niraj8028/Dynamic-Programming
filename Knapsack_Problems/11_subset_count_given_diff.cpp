#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int t[1001][1001];

int subsetcount(int arr[],int n,int sum1){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum1; j++){
            if(i==0){
                t[0][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum1; j++){
            if(arr[i]<j){
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum1];

}

int count(int arr[],int n,int k,int range){
    int sum1,sum2;
    range=sum1+sum2;
    k=sum1-sum2;
    sum1=(range+k)/2;

    int x= subsetcount(arr,n,sum1);
    return x;
}

int main(){
    int n=4;
    int arr[]={1,1,2,3};
    int sum=0;
    int diff=1;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    cout<<count(arr,n,diff,sum);
    return 0;
}