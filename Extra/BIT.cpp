#include<bits/stdc++.h>
using namespace std;
#define N 1000

class BIT{
public:
	int bit[N];
	inline int lowerbit(int i);
	void update(int i,int value);
	int sum(int i);
	void biuld(int n);
	BIT();
};

BIT::BIT()
{
	memset(bit,0,sizeof(bit));
}

inline int BIT::lowerbit(int i)
{
	return i&(-i);
}

void BIT::update(int i,int value)
{
	for(;i<=N;i+=lowerbit(i)) bit[i]+=value;
}

int BIT::sum(int i)
{
	int sum=0;
	for(;i>0;i-=lowerbit(i)) sum+=bit[i];
	return sum;
}

void BIT::biuld(int n)
{
	int i;
	for(i=1;i<=n;i++) update(i,0);
}

int main()
{
	BIT x;
	x.biuld(100);
	cout<<x.sum(5)<<endl;
	x.update(1,1);
	cout<<x.sum(5)<<endl;
	x.update(1,2);
	cout<<x.sum(5)<<endl;
	x.update(5,1);
	cout<<x.sum(5)<<endl;
}