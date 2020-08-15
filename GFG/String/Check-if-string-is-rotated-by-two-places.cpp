/*Mohammed Mudassir Mohiuddin*/
/*
Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0
*/
#include<bits/stdc++.h>
using namespace std;

int Check_by_2(string ostr, string rstr)
{
    if(ostr.length() != rstr.length())
        return 0;
    int len = ostr.length();    
    string antiwise = rstr.substr(len-2, 2) + rstr.substr(0, len-2);
    if(antiwise == ostr) return 1;                    
    string clockwise =  rstr.substr(2) + rstr.substr(0, 2);
    if(clockwise == ostr) return 1;
    return 0;
}

void solve()
{
    string ostr,rstr;
    cin>>ostr>>rstr;
    cout<<Check_by_2(ostr, rstr)<<"\n";
}

int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	    solve();
	return 0;
}