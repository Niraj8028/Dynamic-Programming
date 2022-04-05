#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

vector<string>subsets(string s,int n){
    vector<int>ans;
    for(int i=0; i<(1<<n); i++){
        vector<char>x;
        for(int j=0; j<n; j++){
            if((i && (1<<j)==1){
                
            }
        }
    }
}

int main(){
    string s="ABC";
    int n=3;
    vector<string>ans=subsets(s,n);
    return 0;
}