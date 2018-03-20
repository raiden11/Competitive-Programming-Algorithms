//euler totient function
// for first n numbers

#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define mod 1000000007
#define ll long long int
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

ll etf[100000];

void euler_totient()   // first n
{
    int n,i,j;
    cin>>n;
    rep(i,n)
        etf[i]=i;
    for(i=2;i<=n;i++)
    {
        if(etf[i]==i)
        {
            etf[i]=i-1;
            for(j=2*i;j<=n;j+=i)
            {
                etf[j]=(etf[j]*(i-1))/i;
            }
        }
    }
    for(i=1;i<=n;i++)
        cout<<i<<" "<<etf[i]<<endl;
}


ll phi(ll n)
{
    ll ans = n, k =n;
    for(ll i=2; i*i<=k; i++)
    {
        if(n%i==0)
        {
            while (n%i == 0)
                n/=i;
            ans=(ans/i)*(i-1);
        }
    }
    if (n > 1)
        ans=(ans/n)*(n-1);

    return ans;
}

int main()
{
    int n,i,ans,j,k;
    euler_totient();

    return 0;
}
