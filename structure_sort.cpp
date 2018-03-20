//structure sort

#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
};
bool compare(point a,point b)
{
    if(a.x==b.x)
        return (a.y>b.y);
    else
        return (a.x<b.x);
}
point p[100010];
int main()
{
    int t,i,n,a,b;
    long double ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0.0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+n,compare);
        for(i=1;i<n;i++)
            ans=ans+sqrt(pow(abs(p[i].x-p[i-1].x),2)+pow(abs(p[i].y-p[i-1].y),2));
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<ans<<endl;
    }
    return 0;
}
