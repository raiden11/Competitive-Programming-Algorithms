


#include<bits/stdc++.h>

using namespace std;

#define inf 1013161010
#define mod 1000000007
#define ll long long
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

#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

int a[223456];
class point
{
public:
    double x;
    double y;
    double dist(point a,point b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    double mand(point a,point b)
    {
        return abs(a.x-b.x)+abs(a.y-b.y);
    }
};

class vect
{
public:
    double x,y;
    vect()
    {
        x=0;y=0;
    }
    vect(point a,point b)
    {
        x=b.x-a.x;
        y=b.y-a.y;
    }
    double mode(vect a)
    {
        return (sqrt(a.x*a.x+a.y*a.y));
    }
    vect operator +(vect a)
    {
        vect c;
        c.x=x+a.x;
        c.y=y+a.y;
        return c;
    }
    vect operator -(vect a)
    {
        vect c;
        c.x=x-a.x;
        c.y=y-a.y;
        return c;
    }
    double dot(vect a,vect b)
    {
        return (b.x*a.x + b.y+a.y);
    }
    double cross(vect a,vect b)
    {
        return (a.x*b.y-a.y*b.x);
    }
};

double polygon_area(point a[],int n)
{
    int i=0;
    double ans=0;
    vect c;
    while(i+1<n)
    {
        ans+=c.cross(vect(a[i],a[0]),vect(a[i+1],a[0]));
        i++;
    }
    return ans;
}

double point_to_line(point a,point b,point c,int is_segment)
{
    vect d;
    point e;
    double ans=d.cross(vect(a,b),vect(a,c))/d.mode(vect(a,b));
    if(is_segment)
    {
        if(d.dot(vect(a,b),vect(b,c))>0)
            return e.dist(b,c);
        if(d.dot(vect(b,a),vect(c,a))>0)
            return e.dist(c,a);
    }
    return ans;
}

int main()
{
    int i,j,n;
    point a;

    return 0;
}
