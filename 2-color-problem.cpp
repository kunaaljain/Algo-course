/*
 Testing If graph is Bipartite via 2-coloring
 BFS of Undirected Graph
 Input N No. of nodes 0 to N-1
 Input M No. of edges
 Next M lines two integers x y indicating edge exists between x y
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

queue<int> node;
vector<int> nbour[MAX];
int visited[MAX]={0};
int parent[MAX];
int color[MAX];

int main()
{
	int n,m,i,j,x,y,cur;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		nbour[x].push_back(y);
		nbour[y].push_back(x);
		color[i]=-1;
	}
	node.push(0);
	visited[0]=1;
	color[0]=1;
	while(!node.empty())
	{
		cur=node.front();
		node.pop();
		for(i=0;i<nbour[cur].size();i++)
		{
			if(!visited[nbour[cur][i]])
			{
				visited[nbour[cur][i]]=1;
				node.push(nbour[cur][i]);
				color[nbour[cur][i]]=!color[cur];
			}
			if(color[nbour[cur][i]]!=(!color[cur]))
			{
				cout<<"NOT POSSIBLE";
				return 0;
			}
		}
	}
	cout<<"Coloring is"<<endl;
	cout<<"Color 1"<<endl;
	for(i=0;i<n;i++)
	{
		if(color[i]==0) cout<<i<<" ";
	}
	cout<<endl<<"Color 2"<<endl;
	for(i=0;i<n;i++)
	{
		if(color[i]==1) cout<<i<<" ";
	}
}
