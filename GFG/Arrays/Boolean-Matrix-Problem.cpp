/*
Mohammed Mudassir Mohiuddin 
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1
*/

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int row,col;
	cin>>row>>col;
	int arr[row][col];
	bool row_flg = false, col_flg = false;
	for(int i=0;i<row;i++)
	    for(int j=0;j<col;j++)
	    {
	        cin>>arr[i][j];
	        if(i==0 && arr[i][j] == 1)
	            row_flg = true;
	        if(j==0 && arr[i][j] == 1)
	            col_flg = true; 
	        if(arr[i][j] == 1)
	        {
	            arr[i][0] = 1;
	            arr[0][j] = 1;
	        }
	    }
	 for(int i=1;i<row;i++)
	    for(int j=1;j<col;j++)
	        if(arr[0][j] || arr[i][0]) arr[i][j] = 1;
	 if(col_flg)    
	    for(int i=0;i<row;i++)   arr[i][0] = 1;
	 if(row_flg)    
	    for(int j=0;j<col;j++)   arr[0][j] = 1;   
	 for(int i=0;i<row;i++)
	 {
	    for(int j=0;j<col;j++)
	        cout<<arr[i][j]<<" ";
	    cout<<"\n";     
	 }
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