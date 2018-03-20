
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

int toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
ll dp[20][2][2][2];
int digit,dg;
string a;
// dp [digit no][condition satisfied][less than n or not][actual no has started]

ll solve(int dig, int c, int lim, int s)       //dig condition less started
{
    // digit dig is to be filled

    // s = 1 : start ho gaya
    // lim = 1 : barabar chalra hai
    // c = 1 : digit aa chuki no me

    // cout<<dig<<endl;

    if(dp[dig][c][lim][s])
        return dp[dig][c][lim][s];

    if(dig==dg)
    {
        if(c==1&&s==1)
            return 1;
        else
            return 0;
    }

    int lm;
    if(lim==1)       // barabar chalra hai number abhi n ke
        lm=(a[dig]-48);
    else
        lm=9;


    for(int d=0;d<=lm;d++)
    {
        // new states

        int dig1=dig+1,c1=c,lim1=lim,s1=s;

        if(s1==0&&d!=0)
            s1=1;

        if(c1==0&&d==digit&&s1==1)
            c1=1;

        if(lim1==1&&d<(a[dig]-48))
            lim1=0;

        ll k = solve(dig1,c1,lim1,s1);
        //cout<<dig<<" "<<digit<<" "<<d<<" "<<c1<<" "<<lim1<<" "<<s1<<" "<<k<<endl;
        dp[dig][c][lim][s] += k;
    }

    return dp[dig][c][lim][s];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    cin>>tt;
    while(tt--)
    {
        n=0;
        cin>>a;
        dg=sz(a);
        ll ans=0,k=0;
        for(i=0;i<sz(a);i++)
            n=(n*10)+(a[i]-48);

        for(i=0;i<=9;i++)
        {
            set0(dp);
            digit = i;
            k = solve(0,0,1,0);
            ans+=k;
           // cout<<i<<" "<<k<<endl;
        }
        ll den = (n*10);
        ll g = gcd(den,ans);
        cout<<(ans/g)<<"/"<<den/g<<endl;
    }

    return 0;
}


