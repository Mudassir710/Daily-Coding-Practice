/*
Mohammed Mudassir Mohiuddin
Kth smallest element 
Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int kthSmallest(int arr[], int n, int k){
    // Your code here
    priority_queue<int> pqueue;
    for(int i=0; i<n; ++i)
        /*cout<<arr[i]<<"b ",*/pqueue.push(arr[i]);
    
    while(n != k){
        n--;
        //cout<<pqueue.top()<<" ";
        pqueue.pop();
    }
    return pqueue.top();
    // 3 5 4 2 9
    // 2 3 4 5 9
}

// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    cout << kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends