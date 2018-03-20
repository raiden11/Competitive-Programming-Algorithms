
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define lf long double
#define in(x) scanf("%d",&x);
#define sz(x) ((int)x.size())
#define lld l64d
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rrep1(i,a,b) for(i=a;i>=b;i--)
#define stlfor(i,t) for(auto i =t.begin();i!=t.end();i++)
#define fr freopen("x.txt","r",stdin)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

int a[nn];

//always struct
struct node
{
    int l,r,val;
} seg[nn];

node merge_node(node a, node b)
{
    node c;
    c.l=0;
    c.r=0;
    c.val=0;
    c.val=a.val+b.val;
    if(a.r==-1)
    {
        c.r=b.r;
        c.l=b.l;
    }
    else if(b.r==-1)
    {
        c.r==a.r;
        c.l=a.l;
    }
    else
    {
        c.r=b.r;
        c.l=a.l;
        if(a.r==1 and b.l==1)
            c.val++;
    }
    return c;
}

void create_tree(int low,int high,int pos)
{
    if(low==high)
    {
        if(a[low]==1)
        {
            seg[pos].l=1;
            seg[pos].r=1;
        }
        else
        {
            seg[pos].l=0;
            seg[pos].r=0;
        }
        seg[pos].val=0;
        return;
    }

    int mid=(low+high)>>1;
    create_tree(low,mid,2*pos+1);
    create_tree(mid+1,high,2*pos+2);
    seg[pos]=merge_node(seg[2*pos+1],seg[2*pos+2]);
}

node query(int low,int high,int pos,int x,int y)
{
    if(x>high||y<low)
    {
        node c;
        c.l=-1;
        c.r=-1;
        c.val=0;
        return c;
    }

    else if(x<=low&&y>=high)
        return seg[pos];

    int mid=(low+high)>>1;
    return merge_node(query(low,mid,2*pos+1,x,y),query(mid+1,high,2*pos+2,x,y));
}

void update(int low,int high,int c,int pla,int pos)
{
    if(low==high)
    {
        if(c==1)
        {
            seg[pos].l=1;
            seg[pos].r=1;
            seg[pos].val=0;
        }
        else if(c==0)
        {
            seg[pos].l=0;
            seg[pos].r=0;
            seg[pos].val=0;
        }
        return ;
    }

    int mid=(low+high)>>1;
    if(pla<=mid)
        update(low,mid,c,pla,2*pos+1);
    else
        update(mid+1,high,c,pla,2*pos+2);

    seg[pos]=merge_node(seg[2*pos+1],seg[2*pos+2]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i,j,n,tt,q,idx;
    char c;

    cin>>n>>q;
    /*
    rep(i,n)
    {
        cin>>c;
        if(c=='.')
            a[i]=1;
        else
            a[i]=0;
    }
    */

    create_tree(0,n-1,0);

    // queries
    rep(i,q)
    {
        // cin>>idx>>c;
        idx--;
        node x ;
        if(c=='.')
        {
            update(0,n-1,1,idx,0);
            x = query(0,n-1,0,0,n-1);
        }
        else
        {
            update(0,n-1,0,idx,0);
            x = query(0,n-1,0,0,n-1);
        }

        cout<<x.val<<endl;
    }
    return 0;
}

