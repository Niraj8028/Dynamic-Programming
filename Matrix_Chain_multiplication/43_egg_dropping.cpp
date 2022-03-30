#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int solve(int f,int e){
    if(f==1 || f==0){
        return f;
    }
    if(e==1){
        return f;
    }
    int mn=INT_MAX;
    for(int x=1; x<=f; x++){
        int temp=1+max(solve(x-1,e-1),solve(f-x,e));
        
        mn=min(mn,temp);
    }
    return mn;
}

int main(){
    int e=3;
    int f=5;
    cout<<solve(f,e);
    return 0;
}