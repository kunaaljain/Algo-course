/*
    Stable Marriage Problem.
    Given n men and n women, where each person has ranked all members of the opposite sex with a unique number between 1 and n in order of preference,
    marry the men and women together such that there are no two people of opposite sex who would both rather have each other than their current partners.
    If there are no such people, all the marriages are "stable".

    INPUT:
    N Number of Marriages
    2N lines, each containing preference list of men and than women.

    OUTPUT:
    N lines
    each containing pair man and woman.

    Date: 01/01/2015 19:44
    Author: Kunaal Jain
    Email: kunaalus@gmail.com

*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000
#define INF 100000

int pref_man[MAX][MAX],next[MAX],prior_woman[MAX][MAX],choice_woman[MAX],cur_pos[MAX];
int n;

int main()
{
    //freopen("stable-marriage-problem.in","r",stdin);
    int x,y,i,j,k,last,pos=1;
    int current,position;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) cin>>pref_man[i][j];
        cur_pos[i]=1;
        next[i]=i+1;
    }
    last=n;
    next[last]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>x;
            prior_woman[i][x]=j;
        }
        choice_woman[i]=0;
    }
    while(pos!=0)
    {
        current=pref_man[pos][cur_pos[pos]++];
        if(choice_woman[current]==0) //woman is free
        {
            choice_woman[current]=pos;
            pos=next[pos];
        }
        else //woman in engaged
        {
            if(prior_woman[current][choice_woman[current]]>prior_woman[current][pos]) //better suitor is found
            {
                next[last]=choice_woman[current];
                last=choice_woman[current];
                next[last]=0;
                choice_woman[current]=pos;
                pos=next[pos];
            }
        }
    }
    cout<<"WOMAN----MAN"<<endl;
    for(i=1;i<=n;i++) cout<<i<<"----"<<choice_woman[i]<<endl;
    return 0;
}











