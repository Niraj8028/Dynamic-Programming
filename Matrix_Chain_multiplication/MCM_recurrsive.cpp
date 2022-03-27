#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int mcm(int arr[],int i, int j){
    if(i >=j){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int temp=mcm(arr,i,k)+mcm(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<mn){
            mn=temp;
        }
    }
    return mn;
}
int main(){
    int arr[]={40,20,30,10,30};
    int n=5;
    cout<<mcm(arr,1,n-1);
    return 0;
}