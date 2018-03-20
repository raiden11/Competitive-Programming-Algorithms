
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
ll cnt[nn], mu[nn], mark[nn], f[nn];

void mobius()
{
    // cnt[i] stores (no of prime numbers < i ) i is divisible by till now
    // mu[i] is mobius function
    // mark[i] is 0 for square-free and non-prime numbers
    ll i,j;

    mu[1]=1;


    for(i=2;i<=1e6;i++)
    {
        if(cnt[i]==0)
        {
            mu[i]=-1;
            mark[i]=1;
            for(j=2*i;j<=1e6;j+=i)
            {
                cnt[j]++;
                if(((j/i)%i)==0)
                {
                    mu[j]=0;
                    mark[j]=1;
                }
            }
        }
    }
    for(i=2;i<=1e6;i++)
    {
        if(mark[i]==0)
        {
            if(cnt[i]&1)
                mu[i]=-1;
            else
                mu[i]=1;
        }
    }

    for(i=1;i<=100;i++)
        cout<<mu[i]<<" ";
    cout<<endl;

    for(i=1;i<=1e6;i++)
    {
        for(j=i;j<=1e6;j+=i)
        {
            f[j]+=(i*mu[j/i]);   // can change function from i to something else
        }
    }
    cout<<endl;
    for(i=1;i<=100;i++)
        cout<<f[i]<<" ";
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        mobius();
        while(cin>>n)
        {
            if(!n)
                break;
            ll ans = 0;


        }

    }
    return 0;
}

