#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

vector<vector<char>>subsets(string s,int n){
    vector<vector<char>>ans;
    for(int i=0; i<(1<<n); i++){
        vector<char>x;
        for(int j=0; j<n; j++){
            if((i && (1<<j)==1)){
                x.push_back(s[j]);
            }
        }
        ans.push_back(x);
    }
    return ans;
}

int main(){
    string s="ABC";
    int n=3;
    vector<vector<char>>ans=subsets(s,n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
    }
    return 0;
}