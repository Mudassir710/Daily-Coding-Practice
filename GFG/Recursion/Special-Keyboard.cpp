/*Mohammed Mudassir Mohiuddin*/ 
/*
magine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the number of key.

Output:
Print maximum number of A's. Print -1, if N is greater than 75.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 75
*/ 


#include<bits/stdc++.h>
using namespace std;
int optimal(int n)
{
    if(n < 7) return n;
    int screen[n+1];
    screen[0]=1;
    for(int i=1; i<=6; i++)
    {
        screen[i] = i;
    }
    for(int i = 7; i<=n; ++i)
    {
            screen[i] = max(2 * screen[i - 3], 
                        max(3 * screen[i - 4],  
                            4 * screen[i - 5]
                            )); 
    }
    return screen[n];
    
}
void solve()
{
    int num;
	cin>>num;
	cout<< optimal(num);
}
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    solve();
	    cout<<"\n";
	}
	return 0;
}