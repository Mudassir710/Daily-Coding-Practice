/*
Mohammed Mudassir Mohiuddin
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

Note: O(1) extra space is allowed. Also, try to modify the input array as required.
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int num;
	cin>>num;
	int arr[num];
	for(int i=0;i<num;i++)
	  cin>>arr[i];
	int right = num -1;
	int left = 0;
	//bool max = 1;
	while(right >= left)
	{
	   if(right != left) cout<<arr[right--]<<" "<<arr[left++]<<" ";
	   else
	   { 
	       cout<<arr[right--];left++;
	   }
	}
	cout<<"\n";
//	0 1 2 3 4 5 
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    solve();
	}
	return 0;
}