/*
Mohammed Mudassir Mohiuddin
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    int num;
	    cin>>num;
	    //int arr[num];
	    int zero=0,one=0,two=0;
	    for(int i=0;i<num;i++)
	    {
	        int inp;
	        cin>>inp;
	        if(inp == 0) zero++;
	        else if(inp == 1) one++;
	        else two++;
	    }
	    for(int i=0; i<zero; ++i)
	    {
	        cout<<"0 ";
	    }
	    for(int i=0; i<one; ++i)
	    {
	        cout<<"1 ";
	    }
	    for(int i=0; i<two; ++i)
	    {
	        cout<<"2 ";
	    }
	    cout<<"\n";
	        //cin>>arr[i];
	
	}
	return 0;
}