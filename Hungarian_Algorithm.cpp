
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <unordered_map>
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
#define frc freopen("y.txt","w",stdout)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;
#define pset(n) fixed<<showpoint<<setprecision(n)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2000006;
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

// Refer:
// https://www.cs.umd.edu/class/spring2011/cmsc651/lec10.pdf
// https://www.topcoder.com/community/data-science/data-science-tutorials/assignment-problem-and-hungarian-algorithm/

// This code calculates maximum perfect matching in a weighted bipartite graph
// just initialise the cost matrix creating dummy nodes if count on both sides is not equal
// n = no of vertices on either side
// for minimum, use abs(hungarian()) and negative weight edges


const int N = 2010;
int cost[N][N], max_match, n;
int lx[N], ly[N];
int xy[N], yx[N];
bool S[N], T[N];
int slack[N], slackx[N];
int prv[N];

void init_labels()
{
    set0(lx), set0(ly);
    for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
            lx[x] = max(lx[x], cost[x][y]);
}

void update_labels()
{
    int x, y, delta = inf;
    for(y=0;y<n;y++)
        if(!T[y])
            delta = min(delta, slack[y]);
    for(x=0;x<n;x++)
        if(S[x])
            lx[x]-=delta;
    for (y = 0; y < n; y++)
        if (T[y])
            ly[y] += delta;
     for (y = 0; y < n; y++)
        if (!T[y])
            slack[y] -= delta;
}


void add_to_tree(int x, int prevx)
{
    S[x]=true;
    prv[x]=prevx;
    for(int y=0; y<n;y++)
        if(lx[x] + ly[y] - cost[x][y] < slack[y])
        {
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
}

void augment()
{
    if(max_match == n)
        return ;
    int x, y, root;
    int q[N], wr = 0, rd = 0;
    set0(S), set0(T);
    memset(prv, -1, sizeof(prv));
    for(int x=0;x<n;x++)
    {
        if(xy[x]==-1)
        {
            q[wr++] = root = x;
            prv[x] = -2;
            S[x] = true;
            break;
        }
    }
    for(int y=0;y<n;y++)
    {
        slack[y] = lx[root] + ly[y] - cost[root][y];
        slackx[y] = root;
    }

    while (true)
    {
        while (rd < wr)
        {
            x = q[rd++];
            for (y = 0; y < n; y++)
            if (cost[x][y] == lx[x] + ly[y] && !T[y])
            {
                if (yx[y] == -1) break;
                T[y] = true;
                q[wr++] = yx[y];
                add_to_tree(yx[y], x);
            }
            if (y < n) break;
        }
        if (y < n) break;

        update_labels();
        wr = rd = 0;
        for (y = 0; y < n; y++)
        if (!T[y] && slack[y] == 0)
        {
            if (yx[y] == -1)
            {
                x = slackx[y];
                break;
            }
            else
            {
                T[y] = true;
                if (!S[yx[y]])
                {
                    q[wr++] = yx[y];
                    add_to_tree(yx[y], slackx[y]);
                }
            }
        }
        if (y < n)
            break;
    }

    if (y < n)
    {
        max_match++;
        for (int cx = x, cy = y, ty; cx != -2; cx = prv[cx], cy = ty)
        {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augment();
    }
}

int hungarian()
{
    int ret = 0;
    max_match = 0;
    memset(xy, -1, sizeof(xy));
    memset(yx, -1, sizeof(yx));
    init_labels();
    augment();
    for(int x=0;x<n;x++)
    {
        ret += cost[x][xy[x]];
    }
    return ret;
}

// Problem
int xc[1010], yc[1010], xb[1010], yb[1010];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    cin>>tt;
    while(tt--)
    {
        set0(cost);
        int m, x, y, a, b, c, n;
        cin>>n>>m;
        ::n = max(n, m);

        while(cin>>a>>b>>c)
        {
            if(a==0 and b==0 and c==0)
                break;
            cost[a-1][b-1] = c;
        }

        int ans = 0;
        ans+=hungarian();
        cout<<ans<<endl;
    }
    return 0;
}

