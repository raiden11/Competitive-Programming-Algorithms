//modular_divide

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll fast_pow(ll a,ll m, ll mode)
{
    if(m==0)
        return 1;
    else if(m==1)
        return a;
    ll h=fast_pow(a,m/2,mode);
    if(m%2==0)
        return ((h*h)%mode);
    else
        return ((((h*h)%mode)*a)%mode);
}

ll mmi(ll b, ll mode)
{
    return fast_pow(b, mode-2, mode);
}
// 665507626
// 859350538
// 991506057
int main()
{
    int t;
    ll a,b,k,ans;
    scanf("%d",&t);
    while(t--)
    {
        ll x;
        cin>>x;
        x%=mod;
        cout<<fast_pow(x, 126, mod)%mod<<endl;
    }
    return 0;
}
