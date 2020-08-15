/*
Mohammed Mudassir Mohiuddin
Given a string, the task is to remove duplicates from it. Expected time complexity O(n) where n is length of input string and extra space O(1) under the assumption that there are total 256 possible characters in a string.

Note: that original order of characters must be kept same. 

Input:
First line of the input is the number of test cases T. And first line of test case contains a string.

Output: 
Modified string without duplicates and same order of characters.

Constraints: 
1 <= T <= 15
1 <= |string|<= 1000

Example:
Input:
2
geeksforgeeks
geeks for geeks

Output:
geksfor
geks for
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    //cin>>str;
    getline(cin,str);
    bool chars[256];
    int len = str.length();
	for(int i=0;i<len;i++)
	  chars[int(str[i])] = true;
	for(int i=0;i<len;i++)
	  if(chars[int(str[i])])
	  {
	    cout<<str[i];
	    chars[int(str[i])] = false;
	  }  
	  cout<<"\n";
}
int main()
 {
	int tests;
	cin>>tests;
	cin.ignore();
	while(tests--)
	{
	    solve();
	}
	return 0;
}
