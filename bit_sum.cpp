//bit
//fenwick tree
//O(mlogn)

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
#define lld I64d
#define in(x) scanf("%lld",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
const double pi(3.14159265358979);

int ar[1000];
int bit [1000];
void build(int no,int n)
{
    int idx=no+1;
    while(idx<=n)
    {
        bit[idx]+=ar[no];           // here idx store sum from idx-2^r to idx-1 where r is last set bit in idx
        idx+=(idx&(-idx));          // next---- take twos compliment & with idx and add to idx
    }
}

void update_p(int no,int sum,int n)
{
    int idx=no+1;
    while(idx<=n)
    {
        bit[idx]+=sum;
        idx+=(idx&(-idx));    //see it as.. (idx&(-idx)) gives maximum power of two which divides x and also its 2's compliment
    }
}

int query_r(int no)
{
    int ans=0,idx;
    idx=no+1;
    while(idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));           // parent--- take twos compliment & with idx deduct to idx
    }
    return ans;
}

ll query_p(int no)        //review this
{
    int idx=no+1,z;
    ll sum=bit[idx];
    z=idx-(idx&(-idx));               // identify common path to both(up till  z) and deduct only till then from predecessor
    idx--;
    while(idx!=z)
    {
        sum-=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}

void update_r(int no,int c,int n)
{
    int idx=no+1,k;
    while(idx<=n)
    {
        k=idx&(-idx);                      // k size of array for which inx is responsible
        bit[idx]+=(k*c);                   //add c*size responsible to current bit index
        idx+=k;                            // go to parent
    }
}

int main()
{
    int x,i,j,idx,ans=0,n,m,a,b,c;
    scanf("%d",&n);
    rep(i,n)
        scanf("%d",&ar[i]);

    rep(i,n)
        build(i,n);

    rep(i,n)
    {
        cout<<query_p(i)<<" ";
    }
    cout<<endl;
    scanf("%d",&m);
                        // after this no use of array ar
    printf("1. update point\n2. update range\n3. query point\n4. query range\n");
    while(m--)
    {
        scanf("%d",&x);
        if(x==3)
        {
            scanf("%d",&a);                  // print no at pos a
            printf("%d\n",query_p(a));
        }
        else if(x==2)
        {
            scanf("%d%d%d",&a,&b,&c);         //update array from a to b by adding c
            update_r(a,c,n);
            if(b<n-1)
                update_r(b+1,-c,n);
        }
        else if(x==4)
        {
            scanf("%d%d",&a,&b);           //sum from a to b
            if(a>0)
                printf("%d\n",query_r(b)-query_r(a-1));
            else
                printf("%d\n",query_r(b));
        }
        else if(x==1)
        {
            scanf("%d%d",&a,&b);           // replace pos a with b
            c=b-query_p(a);
            update_p(a,c,n);
        }
        rep(i,n)
        {
            cout<<query_p(i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//testcase
// 11
// 3 2 -1 6 5 4 -3 3 7 2 3
