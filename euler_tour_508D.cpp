
#include<bits/stdc++.h>
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define sz(x) ((int)x.size())
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<b;i++)
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
const double pi(3.14159265358979);

//euler tree
//failed mathod 1 : out of possible paths for a vertex, choose the edge having outer edge in next iteration
// reason : there may be two edges and after it it ends graph
ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
vi g1[50000];
int deg[50000],out[50000];

void euler(int node,int &n,string &s)
{
    int i,f=-1,k;
    for(i=0;i<g1[node].size();i++)
    {
        if(out[g1[node][i]]>0)
        {
            f=i;
            k=g1[node][i];
        }
    }
    if(f!=-1)
    {
        g1[node].erase(g1[node].begin()+f);
        s+=(k%151);
        n--;
        out[k]--;
        euler(k,n,s);
    }
    else
    {
        rep(i,g1[node].size())
            if(out[g1[node][i]]<=0)
            {
                g1[node].erase(g1[node].begin()+i);
                n--;
                s+=(g1[node][i]%151);
            }
    }

    return;
}

int main()
{
    int i,j,n;

    cin>>n;
    int f;
    string str;
    rep(i,n)
    {
        cin>>str;
        g1[str[0]*151+str[1]].pb(str[1]*151+str[2]);
        deg[str[0]*151+str[1]]++;
        deg[str[1]*151+str[2]]--;
        out[str[0]*151+str[1]]++;
    }
    f=-1;
    for(i=0;i<50000;i++)
        if(deg[i]==1)
            f=i;

    if(f==-1)
    {
        rep(i,50000)
            if(g1[i].size()>0)
                f=i;
    }

    string s;
    s+=(f-(f%151))/151;
    s+=f%151;

    euler(f,n,s);

    if(n==0)
    {
        cout<<"YES\n";
        cout<<s<<endl;
    }
    else
        cout<<"NO\n";

    return 0;
}

