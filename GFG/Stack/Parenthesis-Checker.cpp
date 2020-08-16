/*Mohammed Mudassir Mohiuddin*/ 
/*
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.
*/
#include<bits/stdc++.h>
using namespace std;
bool solve()
{
    string str;
    cin>>str;
    int len = str.length();
    if((len%2) != 0)
        return false;
    stack<char> s;
    for(int i=0; i<len; ++i)
    {
        char x,ch = str[i];
        if(ch == '{' || ch == '['  || ch == '(') 
        {
            s.push(ch);
            continue;
        }
        if(s.empty())
            return false;
        switch (ch) 
        { 
        case ')': 
            x = s.top(); 
            s.pop(); 
            if (x == '{' || x == '[') return false;
            break; 
  
        case '}': 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '[') return false;
            break; 
  
        case ']': 
            x = s.top(); 
            s.pop(); 
            if (x == '(' || x == '{') return false;
            break; 
        } 
    }
    if(s.empty())
        return true;
    return false;    
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    if(!solve())
	       cout<<"not balanced\n"; 
	    else
	        cout<<"balanced\n";
	}
	return 0;
} 
