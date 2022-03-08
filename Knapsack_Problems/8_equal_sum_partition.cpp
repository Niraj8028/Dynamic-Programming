#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
bool t[1001][1001];

bool isSubset(int arr[],int n,int x){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=x; j++){
            if(i==0){
                t[0][j]=false;
            }
            if(j==0){
                t[i][0]=true;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][x];

}

bool isPossible(int arr[],int n,int &sum){

    for(int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    if(sum%2==0){
        if(isSubset(arr,n,sum/2)){
            return true;
        }
    }
}
int main(){
    int arr[]={1,5,11,5};
    int n=4;
    int sum=0;
    if(isPossible(arr,n,sum)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    
    return 0;
}