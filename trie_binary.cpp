
// use this trie
// add, del functions
// 817E

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


int tr[10000000][2],nxt = 1;
int cnt[10000000][2];

void add(ll x)
{
    int v = 0, i = 30;
    while(i>=0)
    {
        ll bit = ((x&(1<<i))>0)?1:0;
        if(tr[v][bit] == 0)    // if ith bit is 0
            tr[v][bit] = nxt++;
        cnt[v][bit]++;
        v = tr[v][bit];
        i--;
    }
}

void del(ll x)
{
    int v = 0, i = 30;
    while(i>=0)
    {
        ll bit = ((x&(1<<i))>0)?1:0;
        cnt[v][bit]--;
        int go = tr[v][bit];
        if(cnt[v][bit]==0)
            tr[v][bit]=0;
        v=go;
        i--;
    }
}

int query(ll x,ll y)
{
    ll ans = 0;
    int i = 30, v = 0;
    while(i>=0)
    {
        ll bit = (y&(1<<i));
        if(bit)
        {
            if(x&(1<<i))
            {
                ans+=cnt[v][1];
                v=tr[v][0];
            }
            else
            {
                ans+=cnt[v][0];
                v=tr[v][1];
            }
        }
        else
        {
            if((x&(1<<i)))
                v = tr[v][1];
            else
                v=tr[v][0];
        }
        if(v==0)
            break;
        i--;
    }
    return ans;
}

void solve()
{
    ll i,j,n,ty,x,y;
    cin>>n;
    while(n--)
    {
        cin>>ty>>x;
        if(ty==1)
            add(x);
        else if(ty==2)
            del(x);
        else if (ty==3)
        {
            cin>>y;
            cout<<query(x,y)<<endl;
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

