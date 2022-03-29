#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
unordered_map<string,int>mp;

string hashstring(int i,int j,bool isTrue){
    string s=to_string(i)+"*"+to_string(j)+"*"+to_string(isTrue)+" ";
    return s;
}
int solve(string s,int i,int j,bool isTrue){
    
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return s[i]=='t';
        }
        else{
            return s[i]=='f';
        }
    }
    string temp=hashstring(i,j,1);
    cout<<temp;
    
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    int ans=0;
    for(int k=i+1; k<=j-1; k=k+2){

        string LT=hashstring(i,k-1,1);
        string LF=hashstring(i,k-1,0);
        string RT=hashstring(k+1,j,1);
        string RF=hashstring(k+1,j,0);
        int lt,lf,rt,rf;
        
        if(mp.find(LT)!=mp.end()){
            lt=mp[LT];
        }
        else{
            lt=solve(s,i,k-1,1);
        }
        if(mp.find(LF)!=mp.end()){
            lf= mp[LF];
        }
        else{
            lf=solve(s,i,k-1,0);
        }
        if(mp.find(RT)!=mp.end()){
            lt= mp[RT];
        }
        else{
            rt=solve(s,k+1,j,1);
        }
        if(mp.find(RF)!=mp.end()){
            rf= mp[RF];
        }
        else{
            lt=solve(s,k+1,j,0);
        }
        if(s[k]=='&'){
            if(isTrue){
                ans+=lt*rt;
            }
            else{
                ans+=lt*rf+lf*rt+lf*rf;
            }
        }
        else if(s[k]=='|'){
            if(isTrue==true){
                ans+=lt*rt+lt*rf+lf*rt;
            }
            else{
                ans+=lf*rf;
            }
        }
        else if(s[k]=='^'){
            if(isTrue==true){
                ans+=lt*rf+rt*lf;
            }
            else{
                ans+=lt*rt+lf*rf;
            }
        }    
    }
    return mp[temp];

}
int main(){
    string s="t|f&t^f";
    int i=0;
    int j=s.size()-1;
    cout<<solve(s,i,j,1);
    return 0;
}