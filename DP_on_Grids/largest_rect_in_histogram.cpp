#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

vector<int>l(vector<int>&histo){
    int n=histo.size();
    stack<int>st;
    vector<int>left;
    for(int i=0; i<n; i++){
        if(st.empty()){
            left.push_back(0);
            st.push(i);
        }
        else{
            while(!st.empty() && histo[st.top()]>=histo[i]){
                st.pop();                
            }
            if(st.empty()){
                left.push_back(0);
            }
            else{
                left.push_back(st.top()+1);
                st.push(i);
            }
        }
        
    }
    return left;
}
int rectangle(vector<int>&histo){

}
int main(){
    vector<int>histo={2,1,5,6,2,3};
    vector<int>ans=l(histo);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}