#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int Knapsack(int wt[],int val[],int w,int n){
    if(w==0 || n==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+Knapsack(wt,val,w-wt[n-1],n-1),Knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return Knapsack(wt,val,w,n-1);
    }
}

int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;
    cout<<Knapsack(wt,val,w,n);
    
    return 0;
}