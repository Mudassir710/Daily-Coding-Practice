/*Mohammed Mudassir Mohiuddin*/ 
/*
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1
*/ 

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int N,M,res=0;
	cin>>N>>M;
	string str_N,str_M;
    cin>>str_N>>str_M;
    int dp[N+1][M+1];
	for(int i=0;i<=N;i++)
	    for(int j=0;j<=M;j++)
	    {
	        if(i==0 || j==0) dp[i][j] = 0;
	        else if(str_N[i-1] == str_M[j-1])
	        {
	            dp[i][j] = dp[i-1][j-1] + 1;
	            res = max(res, dp[i][j]);
	        }
	        else dp[i][j] = 0;
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
