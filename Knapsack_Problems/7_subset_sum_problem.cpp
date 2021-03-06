#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
bool t[1001][1001];

bool isSubset_sum(int arr[],int n,int sum){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
            
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];

}
int main(){
    int n=6;
    int arr[n]={2,3,7,8,10};
    int sum=11;

    if(isSubset_sum(arr,n,sum)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }

    
    return 0;
}