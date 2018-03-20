
// problem http://codeforces.com/problemset/problem/817/F
// MEX Queries

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
const int nn = 2000006;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

// get<1>(v[i]) would fetch middle value of this tuple
vector<tuple<ll,ll,ll> >v;
map<ll,ll >place;
set<ll>s;
vector<ll>actual;

int seg[nn];
int lazy[nn];

// how to decide parent node from children's values
int merge_node(int a, int b)
{
    return a+b;
}

// to avoid writing whole thing in each query and update
void lazy_update(int pos, int low,int high)
{
    int type = lazy[pos];
    if(type==1)
        seg[pos]=high-low+1;
    else if(type==2)
        seg[pos]=0;
    else if(type==3)
        seg[pos]=high-low+1-seg[pos];

    // passing on to children
    if(high!=low)
    {
        int mid = (low+high)>>1;

        // suppose the node you are sending update on(children) already has a pending update
        // then check how this update is compatible with that update
        // caution: do not call lazy_update in recursion as it then it would act like an O(n) update, not lazy
        if(lazy[2*pos+1]!=0 and lazy[pos]==3)
            lazy_update(2*pos+1,low,mid);
        if(lazy[2*pos+2]!=0 and lazy[pos]==3)
            lazy_update(2*pos+2,mid+1,high);

        lazy[2*pos+1]=lazy[pos];
        lazy[2*pos+2]=lazy[pos];
    }
    // do not forget to update lazy[pos] to 0
    lazy[pos]=0;
}

void update(int low,int high,int pos,int x,int y,int type)
{

    if(lazy[pos]>0)
        lazy_update(pos,low,high);

    if(x>high or y<low)
        return;

    // whole segment update(lazy req)
    if(x<=low&&high<=y)
{
        lazy[pos]=type;
        lazy_update(pos,low,high);
        return ;
    }

    int mid = (low+high)>>1;
    update(low,mid,2*pos+1,x,y,type );
    update(mid+1,high,2*pos+2,x,y,type );
    seg[pos] = merge_node(seg[2*pos+1],seg[2*pos+2]);
}

// specific function for this problem
int check(int pos,int low,int high)
{
    if(lazy[pos]>0)
        lazy_update(pos,low,high);
    if(seg[pos]<(high-low+1))
        return 1;
    else
        return 0;
}

// rewrite every time acc. to need
ll query(int pos,int low,int high)
{
    if(lazy[pos]>0)
        lazy_update(pos,low,high);

    if(low==high)
        return actual[low];

    int mid = (low+high)>>1;
    if(check(2*pos+1,low,mid))
        return query(2*pos+1,low,mid);
    else
        return query(2*pos+2,mid+1,high);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,q,ty,l,r;
    cin>>n;
    rep(i,n)
    {
        cin>>ty>>l>>r;
        s.insert(l);
        s.insert(r);
        s.insert(r+1);
        v.pb(make_tuple(ty,l,r));
    }

    s.insert(1LL);
    i = 0 ;
    for(auto u:s)
    {
        place[u]=i;
        actual.pb(u);
        i++;
    }
    int sze = sz(actual)-1;

    for(i=0;i<n;i++)
    {
        ty = get<0>(v[i]);
        l = get<1>(v[i]);
        r = get<2>(v[i]);

        update(0,sze,0,place[l],place[r],ty);

        cout<<query(0,0,sze)<<endl;

    }
    return 0;
}


