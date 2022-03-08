#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int t[1001][1001];

void Knapsack(int wt[],int val[],int n, int w){

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j]=max(wt[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }


}
int main(){
    int n=4;
    int wt[n]={1,3,4,5};
    int val[n]={1,4,5,7};
    int w=7;
    memset(t,-1,sizeof(t));
    Knapsack(wt,val,w,n);
    cout<<t[3][3];
    
    return 0;
}