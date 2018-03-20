
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

int main()
{
    int i,j,n,tt;
    OST a;

    a.insert(1);
    a.insert(10);
    a.insert(20);
    a.insert(6);
    a.insert(9);
    a.insert(25);

    //returns iterator to kth smallest element
    cout<<*a.find_by_order(1)<<endl;
    cout<<*a.find_by_order(3)<<endl;
    cout<<*a.find_by_order(0)<<endl;

    cout<<endl;
    //returns no of element in a strictly less than arguments
    cout<<a.order_of_key(9)<<endl;
    cout<<a.order_of_key(-5)<<endl;
    cout<<a.order_of_key(30)<<endl;
    cout<<a.order_of_key(15)<<endl;

    return 0;
}

