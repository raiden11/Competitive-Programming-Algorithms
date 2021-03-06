
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

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

int pw[100];

ll mult(string x,string y, ll len)
{
    if(len==1)
    {
        cout<<x<<" "<<y<<endl;
        return (x[0]-'0')*(y[0]-'0');
    }

    ll m = len/2;
    int i;
    ll fac = 1, fac1 = 1;
    for(i=0;i<m;i++)
        fac*=10;

    fac1= fac;
    for(;i<len;i++)
        fac1*=10;

    string xh = x.substr(0, m);
    string xl = x.substr(m, m);
    string yh = y.substr(0, m);
    string yl = y.substr(m, m);

    ll a = mult(xh, yh, m);
    ll d = mult(xl, yl, m);
    ll e = mult(tostring(toint(xh) + toint(xl)), tostring(toint(yh) + toint(yl)), m) - a - d;

    ll ans = a*(fac) + e*(fac1) + d;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    pw[0]=1;
    for(i=1;i<=15;i++)
        pw[i]=2*pw[i-1];

    while(tt--)
    {
        int m,n;
        string a,b;
        cin>>a>>b;
        m = sz(a);
        n = sz(b);
        for(i=0;i<=15;i++)
            if(pw[i]>=m)
                break;
        for(j=0;j<=15;j++)
            if(pw[i]>=n)
                break;

        i = max(i, j);
        string str="";
        for(j=0;j<pw[i]-m;j++)
            str+='0';
        a = str+a;

        str="";
        for(j=0;j<pw[i]-n;j++)
            str+='0';
        b = str + b;

        cout<<a<<" "<<b<<endl;
        cout<<mult(a, b, pw[i])<<endl;


    }
    return 0;
}

