//bfs
//by me
//using vector of vectors for adjacency list

#include<bits/stdc++.h>
using namespace std;
struct vertex
{
    char col;
    int d;
    int par;
};

int main()
{
    int i,j,n,no,e,temp;
    cout<<"enter no of vertices : ";
    cin>>n;
    queue<int>q;
    vertex l[n+1];
    vector<vector<int> >v;
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
    l[1].col='g';
    l[1].d=0;
    l[1].par=0;
    q.push(1);
    while(q.size()>0)      //!q.empty()
    {
        temp=q.front();
        q.pop();
        for(i=0;i<v[temp].size();i++)
            if(l[v[temp][i]].col=='w')
            {
                l[v[temp][i]].col='g';
                l[v[temp][i]].d=l[temp].d+1;
                l[v[temp][i]].par=temp;
                q.push(v[temp][i]);
            }
        l[temp].col='b';
    }
    cout<<endl;
    for(i=1;i<=n;i++)
        cout<<i<<" "<<l[i].col<<" "<<l[i].d<<" "<<l[i].par<<endl;
    return 0;
}
