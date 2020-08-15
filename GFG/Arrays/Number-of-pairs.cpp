/*Mohammed Mudassir Mohiuddin*/
/*
Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test consists of three lines. The first line of each test case consists of two space separated M and N denoting size of arrays X and Y respectively. The second line of each test case contains M space separated integers denoting the elements of array X. The third line of each test case contains N space separated integers denoting elements of array Y.

Output:
Corresponding to each test case, print in a new line, the number of pairs such that xy > yx.

Constraints:
1 ≤ T ≤ 100
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103

Example:
Input
1
3 2
2 1 6
1 5

Output
3
*/
#include<bits/stdc++.h>
using namespace std; 

long count(long x, long Y[], long n, long NoOfY[]) 
{ 
	if (x == 0) return 0; 

	if (x == 1) return NoOfY[0]; 

	long* idx = upper_bound(Y, Y + n, x); 
	long ans = (Y + n) - idx; 

	ans += (NoOfY[0] + NoOfY[1]); 

	if (x == 2) ans -= (NoOfY[3] + NoOfY[4]); 

	if (x == 3) ans += NoOfY[2]; 

	return ans; 
} 

long countPairs(long X[], long Y[], long m, long n) 
{ 
	long NoOfY[5] = {0}; 
	for (long i = 0; i < n; i++) 
		if (Y[i] < 5) 
			NoOfY[Y[i]]++; 

	sort(Y, Y + n); 

	long total_pairs = 0; 

	for (long i=0; i<m; i++) 
		total_pairs += count(X[i], Y, n, NoOfY); 

	return total_pairs; 
} 

int main()
 {
	int tests;
	long m,n,i,count;
	cin>>tests;
	while(tests--)
	{
	    cin>>m>>n;
	    long X[m],Y[n];
	    for(i=0;i<m;i++)
	        cin>>X[i];
	    for(i=0;i<n;i++)
	       cin>>Y[i];
	    cout<<countPairs(X, Y, m, n)<<"\n";
	}
	return 0;
}