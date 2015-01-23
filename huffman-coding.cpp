#include<bits/stdc++.h>
#include <functional>
using namespace std;

struct node{
	int probabilty;
	node *leftchild;
	node *rightchild;
	node *parent;
};

struct DereferenceCompareNode : public std::binary_function<node*, node*, bool>
{
    bool operator()(const node* lhs, const node* rhs) const
    {
        return lhs->probabilty > rhs->probabilty;
    }
};


void traversal(node *a,string x)
{
	//cout<<a->probabilty<<endl;
	//getchar();
	cout<<a->probabilty<<" "<<x<<endl;
	if((a->leftchild)==NULL) cout<<x<<endl;
	else { traversal(a->leftchild,x+"0"); traversal(a->rightchild,x+"1"); }
	return;
}

int main()
{
	node *x;
	node *y,*z;
	//x= new node;
	priority_queue<node*,vector<node*>,DereferenceCompareNode> q1;
	int i,n,temp;
	n=4;
	for(i=0;i<n;i++) 
	{		
		cin>>temp;
		x = new node;
		x->probabilty=temp;
		x->leftchild=NULL;
		x->rightchild=NULL;
		x->parent=NULL;
		q1.push(x);
	}
	while(q1.size()>1)
	{
		y=q1.top();
		q1.pop();
		z=q1.top();
		q1.pop();
		x=new node;
		x->probabilty=y->probabilty+z->probabilty;
		cout<<x->probabilty<<"X"<<endl;
		x->leftchild=y;
		x->rightchild=z;
		x->parent=NULL;
		q1.push(x);
		//cout<<x->probabilty<<endl;
		//cout<<x->leftchild->probabilty<<endl;
		//cout<<x->rightchild->probabilty<<endl;
	}
	//cout<<x->leftchild->probabilty;
	//cout<<q1.size();
	string a="";

	traversal(x,a);
	return 0;
}