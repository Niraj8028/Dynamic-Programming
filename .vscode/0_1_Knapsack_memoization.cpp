#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int t[1000][1000];

int Knapsack(int wt[],int val[],int w,int n){
    if(w==0 || n==0){
        return 0;
    }
    if(t[n][w]!=-1){
        return t[n][w];
    }
    else{
        if(wt[n-1]<=w){
            return t[n][w]=max(val[n-1]+Knapsack(wt,val,w-wt[n-1],n-1),Knapsack(wt,val,w,n-1));
        }
        else if(wt[n-1]>w){
            return t[n][w]= Knapsack(wt,val,w,n-1);
        }
    }
}

int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;
    memset(t,-1,sizeof(t));
    cout<<Knapsack(wt,val,w,n);
    
    return 0;
}