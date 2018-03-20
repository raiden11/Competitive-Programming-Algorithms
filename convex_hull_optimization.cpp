#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
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

ll dp[nn],a[nn], sum[nn];
vector<pll> lines;
vector<lf> points;
deque<pll>line1;
deque<lf>point1;

lf inter(pll l1, pll l2)
{
    lf x = ((lf)l2.ss-(lf)l1.ss)/((lf)l1.ff-(lf)l2.ff);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {

        cin>>n;
        ll tot = 0;
        rep1(i,1,n)
        {
            cin>>a[i];
            tot = tot + (a[i]*(i));
        }

        for(i=1;i<=n;i++)
            sum[i] = sum[i-1] + a[i];

        lines.pb(mp(0,-1e17));
        points.pb(-1e17);

        ll idx, val, cn, ans=-1e18;
        for(i=1;i<=n;i++)
        {
            cn = (tot - (i)*a[i] + sum[i-1]);
            while(sz(lines)>=2 and
                  inter(mp(i,-sum[i]), lines[sz(lines) - 1]) <= inter(lines[sz(lines) - 1 ], lines[sz(lines)-2]))
            {
                lines.pop_back();
                points.pop_back();
            }
            lines.push_back(mp(i,-sum[i]));
            points.pb(inter(mp(i,-sum[i]), lines[sz(lines) - 1]));

            idx = lower_bound(all(points), a[i]) - points.begin() ;
            val = a[i]*(lines[idx].ff) + lines[idx].ss;
            ans = max(ans, cn + val);
            cout<<i<<" "<<ans<<endl;
        }



        cout<<ans<<endl;


    }
    return 0;
}
