//sieve

#include<bits/stdc++.h>
#include<vector>
#include<math.h>
using namespace std;
int lim=1000000;
double bound=(lim-1)/2;
vector<int>s(bound,0);

// sieve PE 10
// index i represents number 2*i+1
// is prime[i] == 0,
// start marking prime[i] = 1 looping from 2*i*(i+1) in steos of 2*(i+1)
// primes = 2*i+1, where prime[i] == 0

int main()
{
    long long int i,j,k,l,n=1;
    double crosslim =(sqrt(lim)-1)/2;
    vector<int>a;
    for(i=1;i<=crosslim;i++)
    {
        k = 2*i*(i+1);
        l = 2*i+1;
        if(s[i]==0)
        {
            for(j=k;j<=bound;j+=l)
                s[j]=1;
        }
    }
    cout<<s[0]<<endl;
    a.push_back(2);
    for(i=1;i<=bound;i++)
        if(s[i]==0)
        {
            a.push_back(2*i+1);
            n++;
        }
    printf("%d\n",n);
    return 0;
}
