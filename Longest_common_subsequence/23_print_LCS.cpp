#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

string printLcs(string x,string y,int m,int n){
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
               dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
      // we will take help of filled matrix . while travesing backwords we compare X and Y elements and if they same some anyone in the string and reduce i and j. else we check which one is greater t[i-1][j] or t[j][j-1]. Based on that we decrease the i or j; return the reverse of thet array
    string ans="";
    int i=m; int j=n;
    while(i>0 || j>0){
        if(x[i-1]==y[j-1]){
            ans.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    // cout<<dp[m][n];
    reverse(ans.begin(),ans.end());
    cout<<ans.size();
    return ans;
    
}

int main(){
    string x="abcef";
    string y="abxy";
    cout<<printLcs(x,y,x.length(),y.length());
    
    
    return 0;
}