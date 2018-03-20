
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <complex>
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

typedef complex < double > base ;

// THIS IS NOT NTT
void fft(vector<base> & a, int invert)
{
    int n = sz(a);
    if(n==1)
        return ;

    double ang = (2*pi)/n;
    if(invert)
        ang*=-1;

    base nroot = base(cos(ang), sin(ang));
    base w = base(1.0);

    vector<base> even(n/2);
    vector<base> odd(n/2);

    int j = 0;
    for(int i=0;i<n;i+=2)
    {
        even[j] = a[i] ;
        odd[j] = a[i+1] ;
        j++;
    }

    fft(even, invert);
    fft(odd, invert);

    for(int i=0;i<n/2;i++)
    {
        a[i] = even[i] + w*odd[i];
        a[i+n/2] = even[i] - w*odd[i];
        if(invert)
            a[i]/=2, a[i+n/2]/=2;
        w*=nroot;
    }
}

void multiply(vector<int>&a, vector<int>&b, vector<int>&ans )
{
    // we receive two arrays a and and result(a*b) is stores int ans
    // converts from int to complex, used to store f(x) where x is complex root
    vector<base>fa(all(a)), fb(all(b));
    int n = 1;
    while(n<(sz(a)+sz(b)))
        n*=2;

    // add extra coefficients
    fa.resize(n), fb.resize(n);
    fft(fa, 0), fft(fb, 0);
    // now fa, fb contains values of polynomials at complex roots

    for(int i=0;i<n;i++)
        fa[i]*=fb[i];
    ans.resize(n);

    // multiply and invert to point form
    fft(fa, 1);

    //approximation is not necessary always
    //change data type accordingly
    for(int i=0;i<n;i++)
        ans[i] = (int)((fa[i].real())+0.4999);
}

// raise vector a to power b
vector<int> vecpow(vi & a, int b)
{
    if(b==0)
    {
        vector<int> tmp(1, 0);
        tmp[0]=1;
        return tmp;
    }
    vi tmp = vecpow(a, b>>1);
    vi res;
    multiply(tmp, tmp ,res);
    if(b&1)
        multiply(res, a, res);
    int last = 0;
    for(int i=0;i<sz(res);i++)
        if(res[i])
            res[i]=1, last = i+1;
    res.resize(last);
    return res;
}

// SO SLOW
// update with self implemented class of complex numbers
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n, x, k;
        // conversion from coefficient form to point form

        // enter degree + 1 of both polynomials
//        cout<<pset(10);

        // max value can be 1000000
        cin>>n>>k;
        vector<int>a(1010, 0);
        for(i=0;i<n;i++)
        {
            cin>>x;
            a[x]=1;
        }

        // find pow(a, k)
        vi ans = vecpow(a, k);
        for(i=0;i<sz(ans);i++)
            if(ans[i])
                cout<<i<<" ";
        cout<<endl;

    }
    return 0;
}
