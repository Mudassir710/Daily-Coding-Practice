/*
Mohammed Mudassir Mohiuddin
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    string str1,str2;
	    cin>>str1>>str2;
	    int len1 = str1.length(),len2 = str2.length();
	    bool flag = 0;
	    if(len1 == len2)
	    {
	        int arr[256]={0};
	        for(int i=0; i<len1; ++i)
	        {
	            arr[int(str1[i])]++;
	            arr[int(str2[i])]--;
	        }
	        for(int i=0; i<256; i++)
	        {
	            if(arr[i] != 0){
	                flag = 1;
	                break;
	            }
	        }
	    }
	    else flag = 1;
	    if(flag) cout<<"NO\n";
	    else cout<<"YES\n";
	    
	    
	
	}
	return 0;
}