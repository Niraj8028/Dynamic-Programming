#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int Envolopes(vector<vector<int>>dolls){
    int n=dolls.size();

    if(dolls.size()==0){
        return 0;
    }
    sort(dolls.begin(),dolls.end());
    vector<int>dp(n+1,1);
    int ans=1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(dolls[i][0]>dolls[j][0] && dolls[i][1]>dolls[j][i] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }
    for(int i=0; i<n; i++){
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main(){
    vector<vector<int>>dolls={{5,4},{6,4},{6,7},{2,3}};
    int n=4;
    cout<<Envolopes(dolls);
}