/*
Mohammed Mudassir Mohiuddin
Given an array arr[] of N non-negative integers representing the height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
The structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.
*/

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){
    
    int left[n],right[n],res=0;
    left[0] = arr[0];
    for(int i=1; i<n; ++i)
        left[i] = max(left[i-1], arr[i]);
    right[n-1] = arr[n-1];
    for(int i=n-2; i>=0; --i)
        right[i] = max(right[i+1], arr[i]);
    for(int i=0; i<n; ++i)
        res+= min(left[i], right[i]) - arr[i];
    return res;
    // Your code here
    
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends