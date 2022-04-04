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
vector<int>r(vector<int>&histo){
    int n=histo.size();
    stack<int>st;
    vector<int>right;
    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            right.push_back(n-1);
            st.push(i);
        }
        else{
            while(!st.empty() && histo[st.top()]>=histo[i]){
                st.pop();                
            }
            if(st.empty()){
                right.push_back(n-1);
            }
            else{
                right.push_back(st.top()-1);
                st.push(i);
            }
        }
        
    }
    return right;
}
int rectangle(vector<int>&histo){

}
int main(){
    vector<int>histo={2,1,5,6,2,3};
    vector<int>ans=r(histo);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
    }
    return 0;
}