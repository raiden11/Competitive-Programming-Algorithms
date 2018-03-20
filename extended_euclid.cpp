


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x, y, d;
void egcd(ll a, ll b)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        d = a;
        return ;
    }
    egcd(b, a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    egcd(n, m);
    cout<<d<<" "<<x<<" "<<y<<endl;
    return 0;
}
