/*
	Longest Increasing Subsequence
	Dynamic Programming Approach
	Author : Kunaal Jain

*/

#include<bits/stdc++.h>
using namespace std;
#define N 1000

int arr[N],dp[N],prev[N];

int main()
{
	int i,j,n,low,high,len=0,mid,a,b,c;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		dp[i]=prev[i]=0;
	}
	for(i=0;i<n;i++)
	{
		low=0;
		high=len;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(arr[dp[mid]]<arr[i])
				low=mid+1;
			else high=mid-1;
		}
		dp[low]=i;
		prev[i]=dp[low-1];
		if(low>len) len=low;
	}
	c=dp[len];
	b=prev[c];
	for(i=len-1;i>=0;i--)
	{
		a=prev[b];
		prev[b]=c;
		c=b;
		b=a;
	}
	for(i=0;i<=len;i++)
	{
		cout<<arr[b]<<" ";
		b=prev[b];
	}
	return 0;
}