/*
	Using TRIE to SOLVE this
	Problem1: Given an array of integers, we have to find two elements whose XOR is maximum.
	Solution:
	Suppose we have a data structure in which can satisfy two types of queries:
	1. Insert a number X
	2. Given a Y, find maximum XOR of Y with all numbers that have been inserted till now.
*/

#include<bits/stdc++.h>
#include "TRIE.h"
using namespace std;
#define MAXBIT 16

int main()
{
	int i,n,j,k,l,c;
	trie t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>c;
		if(c==1)
		{
			cin>>k;
			t.insert(k);
		}
		else
		{
			cin>>k;
			cout<<t.findmaxxor(k)<<endl;
		}
	}
	return 0;
}


