//bitwise sieve

#include<stdio.h>
#include<vector>
using namespace std;
#define lim 100000000
int a[3333335];
vector<int>prime;
int main()
{
    long long int j;
    int i,s,cnt=0;
    s=int(lim/32)+1;
    for(i=0;i<s;i++)
        a[i]=0;
    for(i=2;i<lim;i++)
        if(i<=10010)
        {
            if((a[i>>5]&(1<<(i&31)))==0)
            {
                for(j=i*i;j<lim;j+=i)
                    a[j>>5]|=(1<<(j&31));
            }
        }
    for(i=2;i<lim;i++)
        if((a[i>>5]&(1<<(i&31)))==0)
        {
            prime.push_back(i);
            cnt++;
        }
    printf("%d\n",cnt);
    return 0;
}
