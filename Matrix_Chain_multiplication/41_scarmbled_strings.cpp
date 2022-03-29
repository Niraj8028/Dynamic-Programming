#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

bool scrambledStrings(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    int n=a.length();
    bool flag1=false;
    bool flag2=false;
    for(int i=1; i<n; i++){
        if(scrambledStrings(a.substr(0,i),b.substr(n-i,i)) && scrambledStrings(a.substr(i,n-i),b.substr(0,n-i))){
            flag1=true;
        }
        if(scrambledStrings(a.substr(0,i),b.substr(0,i)) && scrambledStrings(a.substr(i,n-i),b.substr(i,n-i))){
           flag2=true;;
        }
        
    }
    return flag1|| flag2;

}   

int main(){
    string a="great";
    string b="rgea";
    if(a.length()==b.length()){
        cout<<scrambledStrings(a,b);
    }
    cout<<"false";
    
    return 0;
}