/*
	Author: Kunaal Jain
	Reference : http://people.cs.uct.ac.za/~ksmith/articles/sliding_window_minimum.html

*/


#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

void slidewindow(vector<int> &data,int k)
{
	int i;
	deque<pair<int,int> > window;
	for(i=0;i<data.size();i++)
	{
		while(!window.empty()&&window.back().first>=data[i])
			window.pop_back();
		window.push_back(make_pair(data[i],i));
		while(!window.empty()&&window.front().second<=i-k)
			window.pop_front();
		cout<<window.front().first<<" ";
	}
}

int main()
{
	int n,k,i,temp;
	vector<int> values;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		values.push_back(temp);
	}
	slidewindow(values,k);
	return 0;

}