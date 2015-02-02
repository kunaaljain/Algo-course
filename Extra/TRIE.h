/*
	TRIE.h
	struct node
		value
		left pointer to node
		right pointer to node
	convert function
		to convert number into 16 bit binary
		returns array
	makenode function
		take an integer
		returns pointer to new node intialized to NULL with val=integer passed
	TRIE class
		insert -> 
			takes an integer
			inserts into the TRIE
		findmaxxor ->
			takes an integer
			returns maxxor value of the integer
*/





int* convert(int n)
{
	int* arr;
	arr=(int*)malloc(16*sizeof(int));
	int i;
	for(i=15;i>=0;i--)
	{
		if(n%2==1) arr[i]=1;
		else arr[i]=0;
		n/=2;
	}
	return arr;
}

struct node{
	int val;
	node* left;
	node *right;
};


node* makenode(int val)
{
	node* temp;
	temp=new node();
	temp->val=val;
	temp->left=temp->right=NULL;
	return temp;
}

class trie{
public:
	node* root; 
	void insert(int n);
	int findmaxxor(int n);
	trie();
};

trie::trie()
{
	root=makenode(-1);
}
void trie::insert(int n)
{
	node* temp=root;
	int* arr,i;
	arr=convert(n);
	for(i=0;i<16;i++)
	{
		if(arr[i])
		{
			if(temp->right!=NULL) temp=temp->right;
			else 
			{
				temp->right=makenode(1);
				temp=temp->right;
			}
		}
		else
		{
			if(temp->left!=NULL) temp=temp->left;
			else 
			{
				temp->left=makenode(0);
				temp=temp->left;
			}	
		}
	}
	free(arr);
}

int trie::findmaxxor(int n)
{
	node* temp=root;
	int* arr,i,val=0;
	arr=convert(n);
	for(i=0;i<16;i++)
	{
		if(arr[i]){
			if(temp->left!=NULL){
				temp=temp->left;
				val=val*2+1;
			}
			else
			{
				temp=temp->right;
				val=2*val;
			}
		}
		else
		{
			if(temp->right!=NULL){
				temp=temp->right;
				val=val*2+1;
			}
			else
			{
				temp=temp->left;
				val=2*val;
			}	
		}
	}
	free(arr);
	return val;
}