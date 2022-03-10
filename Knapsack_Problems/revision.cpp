#include "bits/stdc++.h"
using namespace std;
#define vi vector<int>
#define pii vector<pair<int,int>>

int t[1001][1001];
	int subsetSum(int arr[], int n, int sum) {
	    if(n==0 && sum==0) return 1;
	    if(n==0) return 0;
	    
	    if(t[n][sum] != -1) return t[n][sum];
	    
	    if(arr[n-1] <= sum) {
	        return t[n][sum] = subsetSum(arr, n-1, sum-arr[n-1]) + subsetSum(arr, n-1, sum);
	    }
	    else {
	        return t[n][sum] = subsetSum(arr, n-1, sum);
	    }
	}
	
	int perfectSum(int arr[], int n, int sum) {
	    memset(t, -1, sizeof(t));
	    int diff = 1;
	    
	    // total sum of the array;
	    int sum_arr = 0;
	    for(int i=0; i<n; i++) 
	        sum_arr += arr[i];
	        
	    // sum of first subset
	    int first_subset_sum = (diff + sum_arr)/2;
	    return subsetSum(arr, n, first_subset_sum); 
    }

int main(){
    int n=4;
    int arr[]={1,1,2,3};
    int sum=0;
    int diff=1;
    
    return 0;
}

