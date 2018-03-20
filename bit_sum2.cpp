//fenwick tree
// range update point query

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define inf 1000000000
#define mod 1000000007
#define ll long long
#define lld I64d
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
const double pi(3.14159265358979);

int ar[1010],bit[1010],ar1[1010];
void build(int no,int c,int n)
{
    int i=no+1;
    while(i<=n)
    {
        bit[i]+=c;
        i+=(i&(-i));
    }
}

void update_r(int no,int c,int n)
{
    int i=no+1;
    while(i<=n)
    {
        bit[i]+=c;
        i+=(i&(-i));
    }
}

int query_p(int no,int n)
{
    int i = no+1;
    int sum=0;
    while(i>0)
    {
        sum+=bit[i];
        i-=(i&(-i));
    }
    return sum;
}

int main()
{
    int i,j,ans=0,c,x,a,b,n,m;
    in(n)
    rep(i,n)
    {
        in(ar[i]);
    }
    ar1[0]=ar[0];
    for(i=1;i<=n;i++)
        ar1[i]=ar[i]-ar[i-1];
    rep(i,n)
        build(i,ar1[i],n);
    scanf("%d",&m);
    cout<<"1. range update\n2. point query\n";
    while(m--)
    {
        in(x)
        if(x==1)
        {
            scanf("%d%d%d",&a,&b,&c);
            //cout<<n
            update_r(a,c,n);
            if(b<n-1)
                update_r(b+1,-c,n);
        }
        else
        {
            in(a)
            printf("%d\n",query_p(a,n));
        }
    }
    return 0;
}
