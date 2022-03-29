
#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
unordered_map<string ,bool>mp;

string hashx(string a,string b){
    string s=a+"_"+b;
    return b;
}

bool solve(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    string key=hashx(a,b);

    if(mp.find(key)!=mp.end()){
        return mp[key];
    }
    int n=a.length();
    bool cond1,cond2;
    for(int i=1; i<n; i++){
        
        cond1=cond2=false;
        if(solve(a.substr(0,i),b.substr(n-i,i))&& solve(a.substr(i,n-i),b.substr(0,n-i))){
            cond1=true;
        }
        if(solve(a.substr(0,i),b.substr(0,i))&& solve(a.substr(i,n-i),b.substr(i,n-i))){
            cond2=true;
        }
    }
    return mp[key]=cond1 || cond2;


}
int main(){
    string a="great";
    string b="rgeat";
    if(a.length()==b.length()){
        cout<<solve(a,b);
    }
    else{
    cout<<"false";
    }
    
    return 0;
}