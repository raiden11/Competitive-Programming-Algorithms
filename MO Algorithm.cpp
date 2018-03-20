

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

int a[nn],tmp=0,ans[nn];
umii cnt;

struct query
{
    int l,r,buck,idx;
};

bool comp(query a,query b)
{
    if(a.buck !=b.buck)
		return (a.l < b.l);
	return ((a.buck)&1) ? (a.r<b.r) : (a.r>b.r);
}

query q[nn];
void add(int i)
{
    if(cnt[a[i]]==a[i])
        tmp--;
    cnt[a[i]]++;
    if(cnt[a[i]]==a[i])
        tmp++;
}

void rem(int i)
{
    if(cnt[a[i]]==a[i])
        tmp--;
    cnt[a[i]]--;
    if(cnt[a[i]]==a[i])
        tmp++;
}

void MO(int m)   //send no of queries
{
    int i,j;

    int bsize = 300;
    rep(i,m)
    {
        cin>>q[i].l>>q[i].r;
        q[i].buck = q[i].l/bsize;
        q[i].idx=i;
    }

    sort(q,q+m,comp);

    i=1,j=1;
    cnt[a[i]]++;
    if(cnt[a[i]]==a[i])
        tmp++;

    for(int it=0;it<m;it++)
    {
        while(i>q[it].l)
            i--, add(i);
        while(j<q[it].r)
            j++, add(j);
        while(i<q[it].l)
            rem(i), i++;
        while(j>q[it].r)
            rem(j), j--;
        ans[q[it].idx]=tmp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i,j,n,tt,m;

    cin>>n>>m;

    rep1(i,1,n)
        cin>>a[i];

    MO(m);
    for(i=0;i<m;i++)
        cout<<ans[i]<<'\n';

    return 0;
}

