
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

struct point
{
    ll x,y;
} points[nn], pivot;

struct vec
{
    ll x, y;
};

ll cross(vec a,vec b)
{
    return (a.x*b.y-a.y*b.x);
}

lf dist(point a,point b)
{
    return (lf)sqrt((lf)(b.x-a.x)*(b.x-a.x) + (lf)(b.y-a.y)*(b.y-a.y));
}

int orient(point a, point b, point c)
{
    // compare b and c wrt pivot a
    ll tmp = (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
    if(tmp==0)
        return 0;                       // collinear
    else
        return ((tmp<0) ? -1: 1);       // -1 if ccw, 1 if cw
}

bool comp_angle(point a, point b)
{
    //ll d1x,d1y,d2x,d2y;
    //d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    //d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    int tmp = orient(pivot,a,b);
    if(tmp == 0)
    {
        return (dist(a,pivot)<=dist(b,pivot));
    }
    else
        return tmp < 0;
}

stack<point>ch;
void convex_hull(int n)
{
    ll my = inf, pt = -1, mx = inf, i, x, y, j;
    point last, second_last;

    for(i=0;i<n;i++)
    {
        x=points[i].x;
        y=points[i].y;
        if(y<my)
        {
            pt=i;
            my=y;
            mx=x;
        }
        else if(y==my&&x<mx)
        {
            mx=x;
            pt=i;
        }
    }

    pivot = points[pt];
    for(j=pt+1;j<n;j++)
        points[j-1]=points[j];

    n--;
    sort(points,points+n,comp_angle);

    int m = 0;
    for(i=0;i<n;i++)
    {
        while(i<n-1&&orient(pivot,points[i],points[i+1])==0)
            i++;
        points[m]=points[i];
        m++;
    }

    ch.push(pivot);
    ch.push(points[0]);

    for(i=1;i<m;i++)
    {
        last = ch.top();
        ch.pop();
        second_last = ch.top();
        ch.push(last);

        while(orient(second_last, last, points[i])>=0)    // right or linear par pop
        {
            ch.pop();
            last = ch.top();
            ch.pop();
            second_last = ch.top();
            ch.push(last);
        }
        ch.push(points[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int i,j,tt,n;
    ll x,y,z;

    cin>>n;

    rep(i,n)
    {
        cin>>x>>y;
        points[i].x=x;
        points[i].y=y;
    }

    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<(lf)(2*(dist(points[0],points[1])))<<endl;
        return 0;
    }

    convex_hull(n);

   // stack ch contains all the nodes

    return 0;
}

