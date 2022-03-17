#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
unordered_map<string,bool>mp;

bool check(string s1, string s2, string s3,int l1, int l2, int l3, int p1,int p2, int p3){
    if(p3==l3){
        return (p2==l2 && p1==l1)?true:false;
    }
    string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
    if(mp.count(key)){
        return mp[key];
    }
    if(p1==l1){
        return mp[key]=(s2[l2]==s3[l3])?check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1):false;
    }
    if(p2==l2){
        return mp[key]=(s1[l1]==s3[l3])?check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1):false;
    }
    bool one=false;
    bool two=false;
    if(s1[p1]==s3[p3]){
        one=check(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
    }
    if(s2[p2]==s3[p3]){
        two=check(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
    }
    return mp[key]=(one || two);
}

bool solve(string s1,string s2,string s3){
    int l1=s1.length();
    int l2=s2.length();
    int l3=s3.length();
    return check(s1,s2,s3,l1,l2,l3,0,0,0);
}
int main(){
    string s1="aa";
    string s2="bb";
    string s3="aabb";
    cout<<solve(s1,s2,s3);
    
    return 0;
}