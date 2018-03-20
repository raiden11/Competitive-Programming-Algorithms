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

struct entry
{
    int nr[2];
    int p;
} a[nn];

int dp[22][200010], suffix[nn], inv[nn], lcp[nn];

bool cmp(entry a, entry b)
{
    return (a.nr[0]==b.nr[0]) ? (a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]?1:0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    cin>>tt;
    while(tt--)
    {
        string str;
        cin>>str;
        n=sz(str);

        set0(dp);
        set0(lcp);
        set0(suffix);
        set0(inv);

        for(i=0;i<n;i++)
        {
            dp[0][i] = str[i];
        }

        a[0].nr[0]=0;
        a[0].nr[1]=0;
        a[0].p=0;
        int stp, cnt;
        for(stp=1, cnt=1; cnt<n; stp++, cnt*=2)
        {
            for(i=0;i<n;i++)
            {
                a[i].nr[0]=dp[stp-1][i];
                a[i].nr[1]=(i+cnt<n)?(dp[stp-1][i+cnt]) : -1;
                a[i].p=i;
            }

            sort(a, a+n, cmp);
            for(i=0;i<n;i++)
            {
                dp[stp][a[i].p] = (i>0 and a[i].nr[0]==a[i-1].nr[0] and a[i].nr[1] == a[i-1].nr[1]) ? (dp[stp][a[i-1].p]):i;
            }
        }
        for(i=0;i<n;i++)
        {
            suffix[i] = a[i].p;
            inv[a[i].p] = i;
        }

        for(i=0;i<n;i++)
            cout<<suffix[i]<<" ";
        cout<<endl;
//
//        for(i=0;i<n;i++)
//            cout<<inv[i]<<" ";
//        cout<<endl;
        int k =0;

        // inv[i] stores that what is position of suffix at i in suffix array
        // suffix[i] stores starting index of ith largest string in str

        // calculate LCP
        for(i=0;i<n;i++)
        {
            // for suffix starting at i and i+1, lcp(i,i+1) and lcp(i+1, i+2)
            // can differ by at most 1 that too the first letter (str[i]).
            if(inv[i]==n-1)
            {
                k=0;
                continue;
            }

            j = suffix[inv[i]+1];
            // if suffix at i is the kth largest suffix of str, j will contain starting index of (k+1)th largest suffix

            while(i+k<n and j+k<n and str[i+k]==str[j+k])
                k++;
            lcp[inv[i]]=k;
            if(k>0)
                k--;
        }

        for(i=0;i<n;i++)
        {
            cout<<lcp[i]<<" ";
        }
        cout<<endl;

        // calculate distinct substring
        int ans = 0;
        ans = n-suffix[0];
        for(i=1;i<n;i++)
            ans+=(n-suffix[i])-lcp[i-1];

        cout<<ans<<endl;
    }
    return 0;
}
