// merge sort

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

void merges(int n,int a[])
{
    int i,j,k,mid;

    if(n>1)
    {
        mid=n/2;
        int left[mid];
        int right[n-mid];
        for(i=0;i<mid;i++)
            left[i]=a[i];
        for(i=(mid);i<n;i++)
            right[i-mid]=a[i];
        merges(mid,left);
        merges((n-mid),right);
        i=0;
        j=0;
        k=0;
        while(i<mid&&j<(n-mid))
        {
            if(left[i]<right[j])
            {
                a[k]=left[i];
                i++;
                k++;
            }
            else
            {
                a[k]=right[j];
                j++;
                k++;
            }
        }
        while(i<mid)
        {
            a[k]=left[i];
            i++;
            k++;
        }
        while(j<(n-mid))
        {
            a[k]=right[j];
            k++;
            j++;
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int l[n];
    for(i=0;i<n;i++)
        scanf("%d",&l[i]);
    merges(n,l);
    for(i=0;i<n;i++)
    {
        printf("%d",l[i]);
        cout<<" ";
    }
    return 0;
}
