

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
void multiply(int a[10][10], int b[10][10], int c[10][10], int m, int n, int q, int md)
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int i,j,tt;
    int a[10][10], b[10][10], c[10][10];
    int m,n,p,q;

    cout<<"Enter size of matrix 1: "<<endl;
    cin>>m>>n;
    cout<<"Enter matrix 1: "<<endl;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    cout<<"\nEnter size of matrix 2: "<<endl;
    cin>>p>>q;
    cout<<"Enter matrix 2: "<<endl;
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            cin>>b[i][j];

    cout<<endl;
    if(p!=n)
    {
        cout<<"Not Possible"<<endl;
    }
    else
    {
        multiply(a,b,c,m,n,q,1e9);
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                cout<<c[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}

