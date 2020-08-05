/*
Mohammed Mudassir Mohiuddin
Given an array of positive integers. The task is to find inversion count of array. Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll merge(ll arr[], ll temp[], int left, int mid, int right)
{
    ll inv_count = 0;
    int i = left, j = mid, k = left;
    while((i <= mid-1) && (j <= right))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += (mid -i);
        }
    }
    while(i <= mid -1)
        temp[k++] = arr[i++];
        
    while(j <= right)
        temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 

    return inv_count;    
    
}
ll mergeSort(ll arr[], ll temp[], int left, int right)
{
    ll inv_count = 0; 
    if(left < right)
    {
        int mid = (left + right)/2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid+1,right);
        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

void solve()
{
    int num;
	cin>>num;
	ll arr[num];
	for(int i=0; i<num; ++i)
	    cin>>arr[i];
	 ll temp[num];
	 cout<<mergeSort(arr,temp,0,num-1)<<"\n";
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