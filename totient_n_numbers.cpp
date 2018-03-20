//totient for first n numbers

#include<bits/stdc++.h>
using namespace std;

int lowest_prime[1000010], phi[1000010];

void pre_phi()
{
    int i,j;
    for(i=2;i<=1000000;i++)
        if(!lowest_prime[i])
        {
            lowest_prime[i]=i;
            for(j=2*i;j<=1000000;j+=i)
                if(!lowest_prime[j])
                    lowest_prime[j]=i;
        }
    phi[1]=1;
    for(i=2;i<=100000;i++)
    {
        if(lowest_prime[i]==i)
            phi[i] = i-1;
        else if(lowest_prime[i]==lowest_prime[i/lowest_prime[i]] )
            phi[i] = phi[i/lowest_prime[i]]*lowest_prime[i];
        else
            phi[i] = phi[i/lowest_prime[i]]*(lowest_prime[i]-1);
    }
}



int main()
{
    int n;
    pre_phi();
    scanf("%d",&n);
    printf("%d",phi[n]);
    return 0;
}








