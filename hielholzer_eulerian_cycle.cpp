
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


list<int>cyc;
vpii g[1010];
void eulerTour(list<int>::iterator it, int u)
{
    //check before if all degrees are even
    for(int j = 0; j<sz(g[u]); j++)
    {
        pii &v = g[u][j];
        if(v.ss)
        {
            if(u==3)
            {
                cout<<v.ff<<" "<<v.ss<<endl;
            }
            v.ss = 0;
            for(int k=0;k<sz(g[v.ff]);k++)
            {
                pii &bedge=g[v.ff][k];
                if(bedge.ff==u and bedge.ss)
                {
                    bedge.ss=0;
                    break;
                }
            }
            auto c = it;
            c++;
            eulerTour(cyc.insert(c, u), v.ff);
        }
    }
}
/*
1 2
2 3
3 1
3 4
4 5
5 6
6 3
*/
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n, m, u, v;
        cin>>n>>m;
        rep(i, m)
        {
            cin>>u>>v;
            g[u].pb(mp(v, 1));
         //   g[v].pb(mp(u, 1));
        }
        cyc.clear();
        eulerTour(cyc.begin(), 1);
        for(auto it=cyc.begin(); it!=cyc.end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}

