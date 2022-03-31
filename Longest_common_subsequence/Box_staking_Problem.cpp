#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

class box{
    public:
    int l,w,h;
};
bool compare(box a,box b){
    return a.l*a.w<b.l*b.w;
}
int maxHeight(int length[], int width[],int height[],int n){
    box arr[3*n];
    for(int i=0; i<n; i++){
        int idx=0;
        arr[idx].h=height[i];
        arr[idx].l=max(width[i],length[i]);
        arr[idx].w=min(width[i],length[i]);
        idx++;
        arr[idx].h=width[i];
        arr[idx].l=max(height[i],length[i]);
        arr[idx].w=min(height[i],length[i]);
        idx++;
        arr[idx].h=length[i];
        arr[idx].l=max(width[i],height[i]);
        arr[idx].w=min(width[i],height[i]);
        idx++;
        
    }
    int len=3*n;
    sort(arr,arr+len,compare);
    int lis[len];

    for(int i=0; i<len; i++){
        lis[i]=arr[i].h;
    }
    for(int i=1; i<len; i++){
        for(int j=0; j<i; j++){
            if(lis[i]<arr[])
        }
    }

}
int main(){
    
    return 0;
}