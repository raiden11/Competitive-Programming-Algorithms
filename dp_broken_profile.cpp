
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
#include <unordered_map>
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
#define vpll vector<pair<ll,ll> >
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
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

// PROBLEM: http://codeforces.com/gym/101635 G


void multiply(ll a[260][260], ll b[260][260], ll c[260][260], int m, int n, int q,ll md)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
                c[i][j] += ((a[i][k]*b[k][j])%md);
            c[i][j] %= md;
        }
    }
}

void mat_pow(ll m[260][260],ll a[260][260],ll b,int k,ll md)       // power b of matrix m(order k) is stored in a
{
    int i,j;
    if(b==0)
    {
        rep(i, k)
            a[i][i]=1;
        return;
    }
    else if(b==1)               // for b=0 return identity matrix
    {
        rep(i,k)
            rep(j,k)
                a[i][j]=m[i][j];
        return;
    }

    mat_pow(m,a,b/2,k,md);

    ll res[260][260];
    rep(i,k)
        rep(j,k)
            res[i][j]=a[i][j];

    multiply(res,res,a,k,k,k,md);     // Be careful with variable names as third matrix change in multiply, its name should be d/f from first 2
    if(b&1)
    {
        rep(i,k)
            rep(j,k)
                res[i][j]=a[i][j];
        multiply(res,m,a,k,k,k,md);
    }

    return;
}

ll fib[15];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,tt;
    tt=1;
    //cin>>tt;
    fib[0]=1;
    fib[1]=1;
    fib[2]=2;
    for(i=3;i<=10;i++)
        fib[i] = fib[i-1] + fib[i-2];

    while(tt--)
    {
        int n;
        ll m;
        cin>>n>>m;

        // set initial matrix dp[0] for each 0<=mask<(1<<n)
        ll init[260][260];
        set0(init);
        for(int mask=0;mask<(1<<n);mask++)
        {
            ll res = 1, tmp = 0;
            for(i=0;i<n;i++)
            {
                if((1<<i)&mask)
                    tmp++;
                else
                {
                    res*=fib[tmp];
                    tmp=0;
                }
            }
            res*=fib[tmp];
            init[0][mask] = res;
        }
        init[0][(1<<n)] = 1;
        init[0][0] = 0;
        // for each mask calculate how it will be calculated from previous masks
        ll expo[260][260];
        set0(expo);
        expo[(1<<n)][(1<<n)-1] = 1;
        expo[(1<<n)-1][(1<<n)] = 1;
        for(int mask=0; mask<(1<<n); mask++)
        {
            for(int mask1 = mask; mask1>0; mask1 = (mask1-1)&(mask))
            {
                // all subset of mask will be iterated by mask1
                // mask1 means those in which 1X2 will come
                int tmask = mask, pmask = (1<<n)-1;
                for(i=0;i<n;i++)
                    if((1<<i)&mask1)
                    {
                        tmask&=~(1<<i);
                        pmask&=~(1<<i);
                    }

                ll res = 1, tmp = 0;
                for(i=0;i<n;i++)
                {
                    if((1<<i)&tmask)
                        tmp++;
                    else
                    {
                        res*=fib[tmp];
                        tmp=0;
                    }
                }
                res*=fib[tmp];
                expo[pmask][mask] += res;
            }

            // the case when mask1 = 0 ie when no relation with n-1 state
            if(mask>0)
            {
                int tmask = mask;
                ll res = 1, tmp = 0;
                for(i=0;i<n;i++)
                {
                    if((1<<i)&tmask)
                        tmp++;
                    else
                    {
                        res*=fib[tmp];
                        tmp=0;
                    }
                }
                res*=fib[tmp];
                expo[(1<<n)-1][mask] += res;
            }
        }
        expo[0][(1<<n)-1] = 0;
        ll ans[260][260], ans1[260][260];
        set0(ans), set0(ans1);

        mat_pow(expo, ans, m-1, 260, 1000000000);
        multiply(init, ans, ans1, (1<<n)+1, (1<<n)+1, (1<<n)+1, 1000000000);
        cout<<ans1[0][(1<<n)-1]<<endl;

    }
    return 0;
}

