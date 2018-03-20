#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,c,j,i;
    printf("enter number");
    cout<<endl;
    scanf("%d",&n);
    do
    {
    cout<<endl;
    printf("enter choice 1.bin to dec 2.dec to bin ");
    cin>>c;
    if(c==1)
    {
        int s=0,i=0,dig;
        while(n!=0)
        {
            dig=n%10;
            s+=(dig*pow(2,i));
            i++;
            n/=10;
        }
        printf("%d",s);
    }
    else
    {
        i=0;
        int a[10];
        while(n!=0)
        {
            a[i]=n%2;
            i++;
            n/=2;
        }
        for(j=i-1;j>=0;j--)
            printf("%d",a[j]);
    }

    cout<<endl;
    printf("enter number");
    cout<<endl;
    scanf("%d",&n);
    }while(n!=0);
    return 0;
}
