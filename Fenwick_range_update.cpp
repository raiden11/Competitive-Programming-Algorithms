

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
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 212345;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

int bit[nn];
int a[8] = {2,3,6,10,15,11,20,30};
int b[10];

void update(int idx,int n,int val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

int main()
{
    cout<<"hello";
    dbg
    int i,j,n,tt;
    n=8;
    b[0]=a[0];
    for(i=1;i<8;i++)
        b[i]=a[i]-a[i-1];
    dbg
    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;

    return 0;
}

