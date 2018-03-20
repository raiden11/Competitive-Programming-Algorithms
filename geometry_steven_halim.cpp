
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
#define vpii vector<pair<int,int> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2123456;
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

struct point
{
    lf x,y;
    point(){x=0, y=0;}
    point(lf _x, lf _y){ x = _x , y = _y; }
};

bool eq(lf a, lf b)
{
    return fabs(a - b) < EPS;
}

bool point_cmp(point a, point b)
{
    if(a.y==b.y)
        return a.x < b.x;
    return a.y < b.y;
}

lf edist(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

point rotate_ccw(point p, lf angle)        // angle is given in degrees
{
    lf rad = (angle*pi)/180;
    return point(p.x*cos(rad) - p.y*sin(rad),
                 p.x*sin(rad) + p.y*cos(rad) );
}
// LINE
struct line
{
    lf a,b,c;
};

void pointsToLine(point p1, point p2, line & l)
{
    if(fabs(p1.x - p2.x) < EPS)
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    else
    {
        l.a = -(p1.y -p2.y)/(p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a*p1.x) - p1.y;
    }
}

bool parallel(line l1, line l2)
{
    return (fabs(l1.a-l2.a)<EPS and (l1.b-l2.b)<EPS);
}

bool areSame(line l1, line l2)
{
    return (parallel(l1,l2) and fabs(l1.c-l2.c)<EPS);
}

bool intersect(line l1,line l2, point & p)
{
    if(parallel(l1,l2))
        return false;
    p.x = (l2.b*l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b)>EPS )
        p.y = -(l1.a*p.x + l1.c);
    else
        p.y = -(l2.a*p.x + l2.c);
    return true;
}

// VECTOR
struct vec
{
    lf x, y;
    vec(){x=0, y=0;}
    vec(lf _x,lf _y) {x = _x, y = _y;}
};

vec tovec(point a,point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

lf dot(vec a,vec b)
{
    return (a.x*b.x+a.y*b.y);
}

vec scale(vec v, lf s)
{
    return vec(v.x*s, v.y*s);
}

point translate(point p, vec v)
{
    return point(p.x + v.x, p.y + v.y);
}

lf cross(vec a,vec b)
{
    return (a.x*b.y - a.y*b.x);
}

lf norm_sq(vec a)
{
    return a.x*a.x+a.y*a.y;
}

lf distToLine(point p, point a, point b, point &c)
{
    vec ap = tovec(a, p), ab = tovec(a, b);
    lf u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return edist(p, c);
}

lf distToLineSegment(point p, point a, point b, point &c)
{
    // if AB is a point
    if(a.x==b.x and a.y==b.y)
    {
        c = a;
        return edist(p, a);
    }
    vec ap = tovec(a, p), ab = tovec(a, b);
    lf u = dot(ap, ab) / norm_sq(ab);
    if(u<0.0)
    {
        c = point(a.x, a.y);
        return edist(p, a);
    }
    if(u>1.0)
    {
        c = point(b.x, b.y);
        return edist(b, p);
    }
    return distToLine(p, a, b, c);
}

lf angle_between_3_points(point a,point b,point c)
{
    // considering point bas vertex, rays ba and bc
    return acos(dot(tovec(b,a),tovec(b,c))/(edist(a,b)*(edist(b,c))));
}

bool ccw(point p, point q, point r)
{
    return cross(tovec(p, q), tovec(p, r) ) > 0;
}

bool collinear(point p, point q, point r)
{
    return (fabs(cross(tovec(p, q), tovec(p, r) )) < EPS);
}

lf triangle_perimeter(point p1, point p2, point p3)
{
    lf a = edist(p1, p2), b = edist(p2, p3), c = edist(p1, p3);
    return (a+b+c);
}

lf triangle_area(point p1, point p2, point p3)
{
    lf a = edist(p1, p2), b = edist(p2, p3), c = edist(p1, p3);
    lf s = (a+b+c)/2.0;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

// = A/s
lf incircle_radius(point a, point b,point c)
{
    return triangle_area(a, b, c)/(0.5*triangle_perimeter(a, b, c));
}

int incircle(point p1, point p2, point p3, point &ctr, lf &r)
{
    r = incircle_radius(p1, p2, p3);

    line l1, l2;
    lf rr = edist(p1, p2) / edist(p1, p3);
    point p = translate(p2, scale(tovec(p2, p3), rr/(1+rr)));
    pointsToLine(p1, p, l1);

    rr = edist(p2, p1) / edist(p2, p3);
    p = translate(p1, scale(tovec(p1, p3), rr/(1+rr)));
    pointsToLine(p2, p, l2);

    intersect(l1, l2, ctr);
    return 1;
}

// circumradius is a*b*c/4*A
lf circumradius(point p1, point p2, point p3)
{
    lf a = edist(p1, p2), b = edist(p2, p3), c = edist(p3, p1);
    return (a*b*c)/(4.0*triangle_area(p1 ,p2, p3));
}

lf polygon_area(point a[],int n)
{
    int i=0;
    lf ans=0;
    while(i+1<n)
    {
        ans+=cross(tovec(a[i],a[0]),tovec(a[i+1],a[0]));
        i++;
    }
    return (ans/2.0);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    point a[3];

    a[0] = point(0,3);
    a[1] = point(1,4);
    a[2] = point(-3,-3);

    //cout<<(a[1]<a[0])<<endl;

    vec y = tovec(a[2],a[1]);
    cout<<y.x<<" "<<y.y<<endl;

    return 0;
}

