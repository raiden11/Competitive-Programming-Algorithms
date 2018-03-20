//ncr mod m
// m is prime
//n,m,r in int range
//https://discuss.codechef.com/questions/3869/best-known-algos-for-calculating-ncr-m

#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);
/*
Fermat's Little Theorem : for any prime p and any integer a, pow(a,p)-a is an integer modulo p
ie a^p - a is congruent to 0 (mod p)
used to calculate modular multiplicative inverse of a number.. mmi(n)
as mmi(a)= (a^(p-2)) (mod p)
*/

/*
Lucas Theorem :
Lucas's Theorem reduces nCr % M to
(n0Cr0 % M) (n1Cr1 % M) ... (nkCrk % M)

Where,
(nk nk-1...n0) is the base M representation of n
(rk rk-1...r0) is the base M representation of r
*/

ll fact[10000];
ll ifact[10000];

int mo;
ll fast_pow(ll a,ll m)
{
    if(m==0)
        return 0;
    else if(m==1)
        return a;
    ll h=fast_pow(a,m/2);
    if(m%2==0)
        return ((h*h)%mo);
    else
        return ((((h*h)%mo)*a)%mo);
}

ll mmi(ll n,ll p,ll m)          // works only if power modulo m is prime
{
    return fast_pow(n,m-2);
}

void base_conv(ll x,ll m,int a[])
{
    int i=0;
    while(x)
    {
        a[i]=x%m;
        x/=m;
        i++;
    }
}

int main()
{
    ll n,c,r,m,i,ans,j,k;
    cin>>n>>r>>m;
    mo=m;
    int r1[50000];
    int n1[50000];
    memset(r1,0,sizeof(r1));
    memset(n1,0,sizeof(n1));
    base_conv(n,m,n1); // base conversion for lucas
    base_conv(r,m,r1);
    fact[0]=1;
    for(i=1;i<=10000;i++)
        fact[i]=(fact[i-1]*i)%m;
    ifact[1]=1;
    for(i=2;i<=10000;i++)
        ifact[i]=(mmi(i,m-2,m)*ifact[i-1])%m;

    for(i=1;i<=10;i++)
        cout<<fact[i]<<" ";
    cout<<endl;

    for(i=1;i<=10;i++)
        cout<<ifact[i]<<" ";
    cout<<endl;
    return 0;
}
