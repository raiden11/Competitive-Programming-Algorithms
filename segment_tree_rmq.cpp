//segment tree
//range minimum query
//utube video

#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
int a[10000];
int seg[20000];
int x,y;

int getsize(int n)
{
    int s=1;
    for(;s<n;s<<=1);
    return s<<1;
}

void create_tree(int low,int high,int pos)
{
    if(low==high)
    {
        seg[pos]=a[low];
        cout<<pos<<" "<<low<<endl;
        return;
    }
    int mid=(low+high)/2;
    create_tree(low,mid,2*pos+1);
    create_tree(mid+1,high,2*pos+2);
    seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}

int rmq(int low,int high,int pos,int x,int y)
{
    if(x>high||y<low)
        return inf;
    else if(x<=low&&y>=high)
        return seg[pos];
    int mid=(low+high)/2;
    return min(rmq(low,mid,2*pos+1,x,y),rmq(mid+1,high,2*pos+2,x,y));
}

void update(int low,int high,int val,int pla,int pos)
{
    if(low==high)
    {
        seg[pos]=val;
        return ;
    }
    int mid=(low+high)/2;
    if(pla<=mid)
    {
        update(low,mid,val,pla,2*pos+1);
        seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
    }
    else
    {
        update(mid+1,high,val,pla,2*pos+2);
        seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
    }
}

int main()
{
    int n,i,q,ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    create_tree(0,n-1,0);
    for(i=0;i<getsize(n);i++)
        printf("%d ",seg[i]);
    printf("\n");
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d",&ch,&x,&y);
        if(ch==1)                                  //ch == print min
            printf("%d\n",rmq(0,n-1,0));
        else                                       //update for ch==2  x is new value
            update(0,n-1,x,y,0);
    }
    return 0;
}
