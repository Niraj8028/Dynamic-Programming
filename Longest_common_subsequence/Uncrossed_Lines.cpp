#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

int uncrossedLines(int x[],int y[],int m){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=0; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][m];

}
int main(){
    int m=4;
    int x[m]={2,3,2,4};
    int y[m]={2,4,3,4};
    cout<<uncrossedLines(x,y,m);
    
    
    return 0;
}