#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int minSteps(int s[],int n, int k){
    
    unordered_set<int>mp;
    vector<int>count(100000,0);
    for(int i=0; i<n; i++){
        count[s[i]]++;
        mp.insert(s[i]);
    }
    int distinct=mp.size();
    if(k>=distinct){
        return 1;
    }
    
    int eleFre1=0;
    for(int i=0; i<100000; i++){
        if(count[i]==1){
            eleFre1++;
        }
    }
    if(k>=eleFre1){
        distinct=distinct-eleFre1;
    }
    else if(k<eleFre1){
        distinct=distinct-k;
    }
    return distinct;
        
}
int main(){
    int n=6;
    int k=1;
    int arr[n]={6,7,8,6,4,7};
    cout<<minSteps(arr,n,k);
    return 0;
}
