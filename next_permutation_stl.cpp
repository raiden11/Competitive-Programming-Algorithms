
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define inf 1000000000
#define mod 1000000007
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)

int a[55],b[6];
int i,j,n,m,cnt=0;

int check(int arr[])
{
    int fl=1;
    for(i=1;i<m;i++)
    {
        if(arr[i]<arr[i-1])
        {
            fl=0;
            break;
        }
    }
    return fl;
}

int main()
{
    scanf("%d%d",&n,&m);
    rep(i,n)
        scanf("%d",&a[i]);
    rep(i,m)
        scanf("%d",&b[i]);
    int abc[n];
    rep(i,n)
        abc[i]=0;
    for(i=n-m;i<n;i++)
        abc[i]=1;
    do
    {
        int arr[m];
        j=0;
        rep(i,n)
        {
            if(abc[i]==1)
            {
                arr[j]=a[i]+b[j];
                j++;
            }
        }
        if(check(arr)==1)
            cnt++;
    }while(next_permutation(abc,abc+n));
    printf("%d\n",cnt);
    return 0;
}
