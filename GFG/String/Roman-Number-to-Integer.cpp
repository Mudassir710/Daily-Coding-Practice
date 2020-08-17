/*Mohammed Mudassir Mohiuddin*/ 
/*
Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
*/
#include<bits/stdc++.h>
using namespace std;
int value(char r) 
{ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
    return -1;
}
void solve()
{
    int res = 0,len;
    string str;
	cin>>str;
	len = str.length();
	for(int i=0;i<len;i++)
	{
	    int currVal = value(str[i]);
	    if(i+1 < len)
	    {
	        int nextVal = value(str[i+1]);
	        if(currVal < nextVal)
	        {
	            res+= (nextVal - currVal);
	            ++i;
	        }
	        else res+=currVal;
	    }
	    else
	    {
	        res+=currVal;
	    }
	}
	cout<<res<<"\n";  
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
