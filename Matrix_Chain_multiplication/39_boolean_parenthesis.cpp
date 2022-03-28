#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int noOfways(string s,int i,int j,bool isTrue){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue==1){
            return(s[i]=='t');              
        }
        else{
            return(s[i]=='f');  
        }
    }
    int ans=0;
    for(int k=i+1; k<=j-1; k=k+2){
        int lTrue=noOfways(s,i,k-1,1);
        int rTrue=noOfways(s,k+1,j,1);
        int lFalse=noOfways(s,i,k-1,0);
        int rFalse=noOfways(s,k+1,j,0);

        if(s[k]=='|'){
            if(isTrue==true){
                ans=ans+lTrue*rTrue+lTrue*rFalse+lFalse*rTrue;
            }
            else{
                ans+=lFalse*rFalse;
            }
        }
        else if(s[k]=='&'){
            if(isTrue==true){
                ans+=lTrue*rTrue;
            }
            else{
                ans+=lTrue*rFalse+lFalse*rTrue+lFalse*rFalse;
            }
        }
        else if(s[k]=='^'){
            if(isTrue==true){
                ans+=lTrue*rFalse+lFalse*rTrue;
            }
            else{
                ans+=lTrue*rTrue+lFalse*rFalse;
            }
        }
    }
    return ans;
}

int main(){
    string s="t|f&t^f";
    int i=0;
    int j=s.size()-1;
    cout<<noOfways(s,i,j,1);
    
    return 0;
}