/*Mohammed Mudassir Mohiuddin
Majority Element 
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	int num,i;
	cin>>tests;
	while(tests--)
	{
	    cin>>num;
	    bool flag = 0;
	    unordered_map<int,int> umap;
	    for(i=0;i<num;i++)
	    {
	        int inp;
	        cin>>inp;
	        ++umap[inp];
	        if(umap[inp] > num/2)
	        {
	            cout<<inp<<"\n";
	            flag = 1;
	        }
	    }
	    if(!flag) cout<<"-1\n";
	}
	return 0;
}