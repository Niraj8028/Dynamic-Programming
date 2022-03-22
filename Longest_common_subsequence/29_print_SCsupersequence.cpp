#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];

string SCSS(string x,string y,int m,int n){
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
    string s="";
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                s.push_back(x[i-1]);
                i--;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                s.push_back(y[j-1]);
                j--;
            }    
        }
    }
    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(){
    string x="acbcf";
    string y="abcdaf";
    int m=x.length();
    int n=y.length();
    cout<<SCSS(x,y,m,n);

    return 0;
}