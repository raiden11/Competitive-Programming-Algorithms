

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
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
const int N = 12;

void multiply(ll a[N][N], ll b[N][N], ll c[N][N], int m, int n, int q,ll md)
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

void mat_pow(ll m[N][N],ll a[N][N],ll b,int k,ll md)       // power b of matrix m(order k) is stored in a
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

    ll res[N][N];
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i,j,n,tt;
    cin>>tt;
    while(tt--)
    {
        int k;

        cin>>k;
        ll a[N][N], ans[N][N], m[N][N];

        memset(m,0,sizeof(m));
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));

        for(i=0;i<k;i++)
            cin>>a[k-i-1][0];

        for(i=0;i<k;i++)
            cin>>m[0][i];
        cin>>n;
        if(n<=k)
        {

            cout<<a[n-1][0]<<endl;
            continue;
        }
        for(i=1;i<k;i++)
            m[i][i-1]=1;

        ll expo[N][N];
        set0(expo);

        mat_pow(m,expo,n-k,k,1e9);

        multiply(expo,a,ans,k,k,12,1e9);

        cout<<ans[0][0]<<endl;
    }
    return 0;
}
