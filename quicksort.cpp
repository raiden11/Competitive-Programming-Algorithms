//quicksort
//divide and conquer
//clrs pg 170

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<set>
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

// logic:
// for subarray a[p...r] position q is such that all elements at p<=i<q are less than a[q] and q>i>=r are greater than a[q]
// keeping a[r] as pivot element...it can be someone else also..we sort such that a[q] becomes a[r] after swapping
// and then sort both subarrays recursively

// before every loop ... line 45
// elements b/w p and i are less than or equal to x
// b/w i+1 nd j-1 are more than x
// b/w j nd r are unsorted

int a[10000];
int part(int p,int r)
{
    int x=a[r],i,j;
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    cout<<p<<" "<<r<<" "<<i+1<<endl;
    return i+1;
}

int quick(int p,int r)
{
    if(p<r)
    {
        int q=part(p,r);
        quick(p,q-1);
        quick(q+1,r);
    }
}

// take example
// 2 8 7 1 3 5 6 4
int main()
{
    int n,i;
    in(n)
    rep(i,n)
        in(a[i])
    quick(0,n-1);
    rep(i,n)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
