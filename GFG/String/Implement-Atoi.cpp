/*Mohammed Mudassir Mohiuddin*/ 
/*
Implement Atoi 
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.
 
Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains a string str .
Output:
For each test case in a new line output will be an integer denoting the converted integer, if the input string is not a numerical string then output will be -1.

Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=T<=100
1<=length of (s,x)<=10

Example(To be used only for expected output) :
Input:
2
123
21a

Output:
123
-1

Explanation:
Test Case 1: Integer value of '123' is 123.
Test Case 2: Output is -1 as all characters are not digit 
*/ 
// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str)
{
   int len = str.length();
   bool negNum  = false;
   int res = 0;
   for(int i = 0; i < len; ++i )
   {
       char ch = str[i];
       if(i == 0 && ch == '-' ) negNum = true;
       else if(ch >= '0' && ch <= '9')
            res = res*10 + (ch - '0');
        else
            return -1;
   }
   if(negNum) return res*-1;
   return res;
}