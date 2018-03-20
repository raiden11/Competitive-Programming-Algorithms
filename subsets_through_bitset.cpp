
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

int dp[(1<<22) + 3];
int ans[(1<<22)+3],a[(1<<22)+3];
int m[(1<<22)+3];

void solve()
{
    ll i,j,n;
    int mask;

    set0(m);
    cin>>n;
    rep(i,n)
    {
        cin>>a[i];
        m[a[i]]++;
    }

    memset(dp,-1,sizeof(dp));
    memset(ans,-1,sizeof(ans));

    // ans array for storing possible number in a[nn] which is also a subset of mask
    for(mask=0;mask<(1<<22);mask++)
    {
        dp[mask]=m[mask];
        if(m[mask])
            ans[mask]=mask;
    }

    // put here max size of a[i] possible
    for(i=0;i<22;i++)
    {
        for(mask=0;mask<(1<<22);mask++)
        {
            if(mask&(1<<i))
            {
                if(i==0)
                {
                    dp[mask]+=m[mask^(1<<i)];
                    if(ans[mask]==-1 and m[mask^(1<<i)])
                        ans[mask]=mask^(1<<i);
                }
                else
                {
                    dp[mask]+=dp[mask^(1<<i)];
                    if(ans[mask]==-1 and dp[mask^(1<<i)])
                        ans[mask]=ans[mask^(1<<i)];
                }
            }
        }
    }

    int tmp = 0;

    for(i=0;i<n;i++)
    {
        tmp = 0;
        for(j=0;j<22;j++)
            if(!(a[i]&(1<<j)))
                tmp|=(1<<j);
        cout<<ans[tmp]<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    // cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

