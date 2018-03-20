//sieve

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,len=2500000;
    vector<int>a;
    vector<int>b;
    for(i=0;i<2500000;i++)
        a.push_back(0);
    for(i=2;i<len;i++)
        for(j=i*i;j<len;j+=i)
        a[j-1]=1;
    for(i=2;i<len;i++)
        if(a[i-1]==0)
            b.push_back(i);
    return 0;
}
