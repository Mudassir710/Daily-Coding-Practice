/*
Mohammed Mudassir Mohiuddin
Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader.
*/

//Method 1

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    int num,i;
	    cin>>num;
	    int arr[num],temp[num];
	    for(i=0;i<num;i++)
	        cin>>arr[i];
	    temp[num-1] = arr[num-1];  
	    int max = temp[num-1];
	    for(i=num-2; i>=0; i--)
	    {
	        if(arr[i] >= max) max = arr[i];
	        temp[i] = max;
	    }     
	    for(i=0; i<num; ++i)
	    if(temp[i] == arr[i]) cout<<temp[i]<<" ";
	    cout<<"\n";
	
	}
	return 0;
}