/*
Mohammed Mudassir Mohiuddin
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*/

#include<bits/stdc++.h>
using namespace std;
void reverse(string &str,int start,int end)
{
    while(start < end)
    {
        swap(str[start++],str[end--]);
    }
}
void solve()
{
    string str;
	cin>>str;
	reverse(str, 0, str.length()-1);
	int start = 0;
	for(int i=0; i<str.length(); ++i)
	{
	    if(str[i] == '.' ) {
	        reverse(str,start,i-1);
	        start = i+1;
	    }
	}
	reverse(str, start, str.length()-1);
	cout<<str<<"\n";
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




