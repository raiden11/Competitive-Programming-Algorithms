//eratosthenes_optimization

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,lim = 5000000;
    double crosslim=sqrt(lim);
    vector<int>s;
    vector<int>a;
    for(i=0;i<=5000010;i++)
        s.push_back(0);
    for(i=4;i<=lim;i+=2)
        s[i]=1;
    for(i=3;i<=crosslim;i+=2)
    {
        if(s[i]==0)
        {
            for(j=i*i;j<=lim;j+=(2*i))
                s[j]=1;
        }
    }
    for(i=1;i<=5000000;i++)
        if(s[i]==0)
            {printf("%d",i);
            cout<<endl;
            }
    return 0;
}
