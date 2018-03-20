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

ll lim=300000100;
double bound=(lim-1)/2;
unsigned int a[5001100];
// compressed into bits
// use ull to reduce to bound/64;
// reduced to 4.65

void sieve()
{
    // sieve PE 10
    long long int i,j,k,l,n=1;
    double crosslim =(sqrt(lim)-1)/2;
    for(i=1;i<=crosslim;i++)
    {
        k = 2*i*(i+1);
        l = 2*i+1;
        if((a[i>>5]&(1<<(i&31)))==0)
        {
            for(j=k;j<=bound;j+=l)
                a[j>>5]|=(1<<(j&31));
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
        int l,r;
        sieve();

        cin>>l>>r;
        int cnt = 0;
        if(l<=2 and r>=2)
            cnt++;

        l = max(5,l);
        i=l/2;
        if(i&1)
            i++;
        int last = r/2;
        if(r%2==0)
            last--;
        // check only even i because 2*i+1 would be of form 4*j+1
        for(;i<=last;i+=2)
            if((a[i>>5]&(1<<(i&31)))==0)
                cnt++;
        cout<<cnt<<endl;

    }
    return 0;
}
