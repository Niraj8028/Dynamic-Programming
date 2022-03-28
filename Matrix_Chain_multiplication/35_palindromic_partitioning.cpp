#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

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
    if(ispalindrome(s,i,j)){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i; k<j; k++){
        int cost=1+partitions(s,i,k)+partitions(s,k+1,j);
        if(cost<mn){
            mn=cost;
        }
    }
    return mn;
}
int main(){
    string s="nitik";
    cout<<partitions(s,0,4);
    
    return 0;
}