/*
Mohammed Mudassir Mohiuddin
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
*/

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
	    int arr[num];
	    for(i=0;i<num;i++)
	        cin>>arr[i];
	   int start =0, end =0; 
	   i=0;
	   bool flag = 1;
	   while(i<num-1)
	   {
	       while(i < num-1 && arr[i+1] <= arr[i]) ++i;
	       if(i == num-1) break;
	       start = i++;
	       while(i < num  && arr[i] >= arr[i-1]) ++i;
	       end = i -1;
	       cout<<"("<<start<<" "<<end<<") ";
	       flag=0;
	   }    
	   if (flag) cout<<"No Profit";
	   cout<<"\n";
	}
	return 0;
}