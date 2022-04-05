#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
bool dp[1001][1001];

bool WordBreak(string s, vector<string>dict){
    int n=s.size();
    unordered_set<string>myset;
    for(int i=0; i<dict.size(); i++){
        myset.insert(dict[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                dp[i][j]=false;
            }
        }
    }
    for(int i=1; i<=n; i++){
        int start=1;
        int end=i;

        while(end<=n){
            string temp=s.substr(start-1,i);
            if(myset.find(temp)!=myset.end()){
                dp[start][end]=true;
            }
            else{
                for(int j=start; j<end; i++){
                    dp[start][end]=dp[start][i] && dp[i+1][end];
                }
                
            }
            start++;
                end++;
        }

    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[1][n];
}
int main(){
    vector<string>dict={"my","pen"};
    string s="mypen";
    
    
    int n=s.size();
    cout<<WordBreak(s,dict);
    return 0;
}