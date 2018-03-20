#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int prime(int i)
{
    long int f;
    double r;

    if (i == 1)
        return 0;
    else if (i < 4)
        return 1;
    else if (i%2 == 0)
        return 0;
    else if (i < 9)
        return 1;
    else if (i%3 == 0)
        return 0;
    else
    {
        r = sqrt(i);
        f = 5;
        while (f <= r)
        {
            if (i % f == 0)
                return 0;
            else if (i %(f+2) == 0)
                return 0;
            f += 6;
        }
    }
    return 1;
}
int main()
{
    int t;
    int a,b,j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&a,&b);
        for(j = a;j <= b;j++)
            if (prime(j) == 1)
                {
                    printf("%d",j);
                    cout<<endl;

                }
    }
    return 0;
}
