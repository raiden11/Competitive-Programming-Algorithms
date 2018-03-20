//dfs
//by me

#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    char col;
    int par;
    int ta;
    int tf;
}l[1000];
vector<vector<int> >v;
int tim;                   //declared name as time initially..........giving error
void dfs(int i)
{
    int j;
    l[i].col='g';
    tim=tim+1;
    l[i].ta=tim;
    for(j=0;j<v[i].size();j++)
        if(l[v[i][j]].col=='w')
        {
            l[v[i][j]].par=i;
            dfs(v[i][j]);
        }
    tim=tim+1;
    l[i].tf=tim;
    l[i].col='b';
}
int main()
{
    int i,j,n,no,e;
    cout<<"enter no of vertices : ";
    cin>>n;
    queue<int>q;
    v.resize(n+1);
    for(i=1;i<=n;i++)
    {
        cout<<"enter no of edges from "<<i<<" : ";
        cin>>no;
        if(no>0)
        {
            cout<<"enter the edges : ";
            for(j=0;j<no;j++)
            {
                cin>>e;
                v[i].push_back(e);
            }
        }
    }
    for(i=1;i<=n;i++)
        l[i].col='w';
    for(i=1;i<=n;i++)
        if(l[i].col=='w')
            dfs(i);
    for(i=1;i<=n;i++)
        cout<<l[i].col<<" "<<l[i].par<<" "<<l[i].ta<<" "<<l[i].tf<<" "<<endl;
}
