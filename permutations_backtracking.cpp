//permutations of string

#include<bits/stdc++.h>
using namespace std;
int ans=0,n;
void swa(int*x,int*y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}
void permute(int l,int str[])
{
    int i;
    if(l==n-1)
    {
        ans++;
        for(i=0;i<n;i++)
            printf("%d ",str[i]);
        printf("\n");
    }
    else
    {
        for(i=l;i<=n-1;i++)
        {
            swa(str+l,str+i);
            permute(l+1,str);
            swa(str+l,str+i);
        }
    }
}
int main()
{
    int i,str[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&str[i]);
    permute(0,str);
    printf("%d\n",ans);
    return 0;
}
