/*
	Author: Kunal Jain

*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int parent[MAX],rank[MAX],MST[MAX];

inline void makeset(int x)
{
	parent[x]=x;
	rank[x]=0;
}

int findset(int x)
{
	if(!parent[x]==x) parent[x]=findset(parent[x]);
	return parent[x];
}

void unionset(int x,int y)
{
	int xroot,yroot;
	xroot=findset(x);
	yroot=findset(y);
	if(xroot==yroot) return;
	else
	{
		if(rank[xroot]<rank[yroot])
			parent[xroot]=yroot;
		else if(rank[xroot]>rank[yroot])
			parent[yroot]=xroot;
		else {
			parent[xroot]=yroot;
			rank[yroot]++;
		}
	}
	return;
}

struct edge{
	int u,v,weight;
};

bool comp(const edge &a,edge &b)
{
	return a.weight<b.weight;
}
int main()
{	
	int V,E,i,cost=0;
	edge e[MAX];
	cin>>V>>E;
	for(i=0;i<V;i++) makeset(i);
	for(i=0;i<E;i++) {
		cin>>e[i].u>>e[i].v>>e[i].weight;
		MST[i]=0;
	}
	sort(e,e+E,comp);
	for(i=0;i<E;i++)
	{
		if(findset(e[i].u)!=findset(e[i].v))
		{
			cost+=e[i].weight;
			MST[i]=1;
			unionset(e[i].u,e[i].v);
		}
	}
	cout<<"Cost: "<<cost<<endl<<"Edges are:"<<endl;
	for(i=0;i<V;i++) if(MST[i]==1) cout<<e[i].u<<" "<<e[i].v<<endl;
	return 0;
}