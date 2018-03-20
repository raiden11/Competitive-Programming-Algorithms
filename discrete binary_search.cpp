//binary search
//topcoder
//discrete
// like lower_bound and upper_bound


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define inf 1000000000
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

int check(int x)
{
    if (x<=2)
        return 1;
    else
        return 0;
}

// consider arr as 111111000000

// finds last element which is 1
// if there is no 1 b/w l and r, (least possible value of l) - 1 is returned

int bs1()
{
    int l=3, r=100000;
    while(l<r)
    {
        int mid = (l+r+1)>>1;
        if(check(mid))
            l=mid;
        else
            r=mid-1;
    }
    if(check(l))
        return l;
    else
        return l-1;
}


// finds element with first 0
// if there is no 0 b/w l and r, (highest possible r) + 1 is returned

int bs0()
{
    int l=0,r=100000;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid;
    }
    if(check(r)==0)
        return r;
    else
        return r+1;
}

int main()
{
    int x = bs1();
    cout<<x<<endl;

    x = bs0();
    cout<<x<<endl;

    return 0;
}
