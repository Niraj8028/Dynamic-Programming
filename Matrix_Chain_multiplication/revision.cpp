
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
int main(){
    string s="i";
    cout<<ispalindrome(s,0,4);
    return 0;
}