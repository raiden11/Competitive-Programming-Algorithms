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

int vroot[nn],l[nn],r[nn];  //version root
int seg[3*nn],a[nn],nodes=0;

int merge_node(int x,int y)
{
    return x+y;
}

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        seg[pos]=a[lo];
        l[pos]=-1;
        r[pos]=-1;
        nodes = max(nodes,pos);
        return ;
    }
    int mid = (lo+hi)>>1;
    build(2*pos+1, lo, mid);
    build(2*pos+2, mid+1, hi);
    l[pos]=2*pos+1;
    r[pos]=2*pos+2;
    seg[pos]=merge_node(seg[2*pos+1],seg[2*pos+2]);
}

// prev refers to the index of node in previous segtree version
void update(int pos, int prev, int pla,int x, int lo,int hi)
{
    if(lo==hi)
    {
        seg[pos]=x;
        l[pos]=-1;
        r[pos]=-1;
        return ;
    }
    int mid = (lo+hi)>>1;
    l[pos] = l[prev];
    r[pos] = r[prev];
    if(pla<=mid)
    {
        nodes++;
        l[pos]=nodes;
        update(nodes, l[prev], pla, x, lo, mid);
    }
    else
    {
        nodes++;
        r[pos]=nodes;
        update(nodes, r[prev], pla, x, mid+1, hi);
    }
    seg[pos] = merge_node(seg[l[pos]],seg[r[pos]]);
}

int query(int pos, int x,int y, int lo,int hi)
{
    if(y<lo or x>hi)
        return 0;
    else if(x<=lo and hi<=y)
        return seg[pos];

    int mid = (lo+hi)>>1;
    return (query(l[pos],x,y,lo,mid) + query(r[pos],x,y,mid+1,hi));
}


void solve()
{
    ll i,j,n,t=0,q,ty,x,y,after,pla;
    // enter q queries on update and sum of elements  of an array

    cin>>n>>q;
    rep(i,n)
        cin>>a[i];

    build(0,0,n-1);

    vroot[0]=0;

    while(q--)
    {
        t++;
        cout<<"query "<<t<<endl;
        cin>>ty;
        if(ty==0)
        {
            // upadte
            cin>>pla>>x;            // element at pos replaced to x
            nodes++;
            vroot[t]=nodes;
            update(vroot[t], vroot[t-1],pla,x,0,n-1);
        }
        else
        {
            //sum
            cin>>after>>x>>y;       // return sum from x to y after query 'after'
            vroot[t]=vroot[t-1];
            int ans = query(vroot[after], x, y, 0, n-1);
            cout<<ans<<endl;

        }
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

