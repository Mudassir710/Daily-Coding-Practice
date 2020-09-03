/*Mohammed Mudassir Mohiuddin*/ 
/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4
*/ 

#include<bits/stdc++.h>
using namespace std;
int R=0,C=0;
void DFS(vector<vector<int>> &arr, int i, int j, int oldcol, int newcol)
{
    if(i < 0 || j < 0 || i >= R || j >= C) return;
    
    if(arr[i][j] != oldcol) return;
    
    arr[i][j]  = newcol;
    
    DFS(arr,i-1,j,oldcol,newcol);
    DFS(arr,i,j-1,oldcol,newcol);
    DFS(arr,i+1,j,oldcol,newcol);
    DFS(arr,i,j+1,oldcol,newcol);
}
void solve()
{
    int r,c;
	cin>>r>>c;
	R = r; C = c;
	vector<vector<int>> arr(r, vector<int>(c,0));
	for(int i=0;i<r;i++)
	  for(int j=0;j<c;j++)
	    cin>>arr[i][j];
	int x, y, color;
	cin>>x>>y>>color;
	DFS(arr,x,y,arr[x][y],color);
	for(int i=0;i<r;i++)
	  for(int j=0;j<c;j++)
	    cout<<arr[i][j]<<" ";
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
