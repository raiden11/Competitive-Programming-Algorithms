//gcd algo

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,r,t,a1,b1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        a1=max(a,b);
        b1=min(a,b);
        r = a1 % b1;
        while(r!=0)
        {
            a1=b1;
            b1=r;
            r=(a1%b1);
        }
        printf("%d\n",b1);
    }
    return 0;
}
