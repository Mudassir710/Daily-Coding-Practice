/* Mohammed Mudassir Mohiuddin
Missing number in array 
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	//long num,i;
	cin>>tests;
	while(tests--)
	{
	    int num;
	    cin>>num;
	    //long arr[num];
	    int res=1;
	    for(int i=2;i<=num;i++)
	    {
	        int inp;
	        cin>>inp;
	        res^=inp;
	        res^=i;
	    }
	     cout<<res<<"\n";
	
	}
	return 0;
}