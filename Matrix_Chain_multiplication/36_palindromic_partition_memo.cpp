#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
int dp[1001][1001];
bool ispalindrome(string s,int i,int j){
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
        return true;
    }
}
int partitions(string s,int i,int j){
    if(i>=j){
        return 0;
    }   
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(ispalindrome(s,i,j)){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int temp=1+partitions(s,i,k)+partitions(s,k+1,j);
        if(mn>temp){
            mn=temp;
        }
        
    }
    dp[i][j]=mn;
    return dp[i][j];
    
}
int main(){
    string s="nitik";
    memset(dp,-1,sizeof(dp));
    cout<<partitions(s,0,4);
    return 0;
}