/*Mohammed Mudassir Mohiuddin*/
/*
Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:
Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string str;
    cin>>str;
    int len = str.length(), res = INT_MIN,j=0;
    vector<int> lastIndex(256, -1); 
    //int lastIndex[256] = {0};
    for(int i=0; i<len; ++i )
    {
        j = max(j, lastIndex[int(str[i])] + 1);
        res = max(res, i-j+1);
        lastIndex[int(str[i])] = i;
    }
    cout<<res<<"\n";
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	    solve();
	return 0;
}