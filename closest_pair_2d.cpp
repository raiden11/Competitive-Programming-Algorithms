
#include<bits/stdc++.h>

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

int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
string tostring ( int number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 212345;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }

struct point
{
    int x;
    int y;
};

point points[nn];

bool comp(point a,point b)
{
    return a.x<b.x;
}

bool comp1(point a,point b)
{
    return a.y<b.y;
}

lf dist(int l,int r)
{
    return sqrt((points[l].x-points[r].x)*(points[l].x-points[r].x) + (points[l].y-points[r].y)*(points[l].y-points[r].y));
}

lf solve(int l,int r)
{
    cout<<l<<" "<<r<<endl;
    if(l==r)
        return inf;
    if(r-l==1)
    {
        return(dist(l,r));
    }

    if(r-l==2)
    {
        return min(dist(l,l+1),min(dist(l,l+2), dist(l+1,l+2)));
    }

    int i,j;
    lf mid = (l+r)/2;

    /*for(i=l;i<=r;i++)
    {
        if(points[i].x>mid)
            break;
    }
    i--;
    */
    //cout<<l<<" "<<mid<<" "<<r<<endl;
    lf delta = min(solve(l,mid), solve(mid+1,r));

    point strip[50010];
    int k = 0;
    for(i=l;i<=r;i++)
    {
        if(abs(points[i].x-mid)<=delta+0.005)
        {
            strip[k] = points[i];
            k++;
        }
    }

    sort(strip,strip+k, comp1);

    lf ans = delta;
    for(i=0;i<k;i++)
    {
        j=i-1;
        while(true)
        {
            lf tmp = sqrt(pow(strip[i].x-strip[j].x,2) + pow(strip[i].y-strip[j].y,2));
            ans = min(ans,tmp);
            if(tmp>delta)
                break;
            j--;
        }
    }

    delta = min(ans,delta);
    return delta ;
}

int main()
{
    int i,j,n,tt,u,v,x,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        points[i].x = x;
        points[i].y = y;
    }

    sort(points, points+n,comp);
    lf ans = solve(0,n-1);
    cout<<ans<<endl;
    return 0;
}

