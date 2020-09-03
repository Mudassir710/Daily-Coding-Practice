/*Mohammed Mudassir Mohiuddin*/ 
/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that from each cell you can either move to right or down.

Input:
The first line of input contains an integer T, denoting the number of test cases. The first line of each test case is M and N, M is number of rows and N is number of columns.

Output:
For each test case, print the number of paths.

Constraints:
1 ≤ T ≤ 30
1 ≤ M,N ≤ 10

Example:
Input
2
3 3
2 8

Output
6
8

Explanation:
Testcase 1: Let the given input 3*3 matrix is filled as such:
A B C
D E F
G H I
The possible paths which exists to reach 'I' from 'A' following above conditions are as follows:
ABCFI, ABEHI, ADGHI, ADEFI, ADEHI, ABEFI
*/ 


#include<bits/stdc++.h>
using namespace std;
// Dp Sol
void solve()
{
    int r,c;
	cin>>r>>c;
	int arr[r][c];
	for(int i=0;i<r;i++)
	  for(int j=0;j<c;j++){
	      if(i == 0 || j == 0) arr[i][j] = 1;
	      else arr[i][j] = arr[i-1][j] + arr[i][j-1];
	  }
	cout<<arr[r-1][c-1]<<"\n";    
}
// Rec Sol
int paths(int r, int c)
{
    if(r==0 || c==0)
    {
      //arr[r][c] = 1;
      return 1;
    } 
    return paths(r-1, c) + paths(r, c-1);
}
void solve1()
{
    int r,c;
	cin>>r>>c;
	cout<< paths(r-1, c-1)<<"\n";
}	
int main()
 {
	int tests;
	cin>>tests;
	while(tests--)
	{
	    solve1();
	}
	return 0;
}