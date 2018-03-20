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
#define frc freopen("y.txt","w",stdout)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;
#define pset(n) fixed<<showpoint<<setprecision(n)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

struct node
{
    int c[3];
}seg[500000];
int lazy[500000];

node merge_node(node a, node b)
{
    node tmp;
    tmp.c[0]=a.c[0]+b.c[0];
    tmp.c[1]=a.c[1]+b.c[1];
    tmp.c[2]=a.c[2]+b.c[2];
    return tmp;
}

void create_tree(int low,int high,int pos)
{
    if(low==high)
    {
        seg[pos].c[0%3]++;
        return;
    }

    int mid=(low+high)>>1;
    create_tree(low,mid,2*pos+1);
    create_tree(mid+1,high,2*pos+2);
    seg[pos]=merge_node(seg[2*pos+1],seg[2*pos+2]);
}

int query(int low,int high,int pos,int x,int y)
{
    if(lazy[pos]>0)
    {
        int d = lazy[pos]%=3;
        lazy[2*pos+1]+=d;
        lazy[2*pos+2]+=d;
        node tmp ;
        int i;
        rep(i,3)
            tmp.c[i]=seg[pos].c[(i-d+3)%3];
        seg[pos]=tmp;
        lazy[pos]=0;
    }
//    cout<<pos<<endl;

    if(x>high||y<low)
    {
//        cout<<"nop "<<pos<<endl;
        return 0;
    }

    if(low==high or (x<=low&&high<=y))
    {
//        cout<<"eq "<<pos<<endl;
        return seg[pos].c[0];
    }

    int mid=(low+high)>>1;
    return query(low,mid,2*pos+1,x,y) + query(mid+1,high, 2*pos+2,x,y);
}

void update(int low,int high,int x, int y,int pos)
{
    if(lazy[pos]>0)
    {
        int d = lazy[pos]%=3;
        lazy[2*pos+1]+=d;
        lazy[2*pos+2]+=d;
        node tmp ;
        int i;
        rep(i,3)
            tmp.c[i]=seg[pos].c[(i-d+3)%3];
        seg[pos]=tmp;
        lazy[pos]=0;
    }

    if(y<low||high<x)
    {
//        cout<<" nope "<<pos<<endl;
        return ;
    }

    else if(low==high or (x<=low and high<=y))
    {
  //      cout<<" eq "<<pos<<endl;
        node tmp;
        int i;
        rep(i,3)
            tmp.c[i]=seg[pos].c[(i-1+3)%3];
        seg[pos]=tmp;
        lazy[2*pos+1]++;
        lazy[2*pos+2]++;

        return;
    }

    int mid=(low+high)>>1;
    update(low,mid,x,y,2*pos+1);
    update(mid+1,high,x,y,2*pos+2);
    seg[pos]=merge_node(seg[2*pos+1],seg[2*pos+2]);

    return;
}

void solve()
{
    ll i,j,n,q;
    int ty,x,y;
    cin>>n>>q;
    create_tree(0,n-1,0);
    while(q--)
    {
        cin>>ty>>x>>y;
        if(ty==0)
            update(0,n-1,x,y,0);
        else
            cout<<query(0,n-1,0,x,y)<<endl;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;

    tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

