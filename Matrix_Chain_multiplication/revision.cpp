
#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>
unordered_map<string,int>mp;
string hashstring(int i,int j,bool isTrue){
    string s=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
    return s;
}
int main(){
    int i=1;
    int j=2;
    bool istrue=1;
    string s=hashstring(i,j,istrue);
    mp[s]=2;
    cout<<mp[s];
}