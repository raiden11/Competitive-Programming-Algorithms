//kmp
//tushar roy

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[1000],b[1000];
    int i,j,arr[1000];
    scanf("%s%s",&a,&b);

    i=1, j=0;
    arr[0]=0;
    while(i<strlen(b))
    {
        while(b[i]!=b[j]&&j>0)
            j=arr[j-1];
        if(b[j]==b[i])
        {
            arr[i]=j+1;
            j++;
        }
        else
            arr[i]=0;
        i++;
    }

    i=0, j=0;
    int f=0, cnt=0;
    while(i<strlen(a))
    {
        while(a[i]!=b[j]&&j>0)
            j=arr[j-1];
        if(a[i]==b[j])
        {
            j++;
            i++;
        }
        else
            i++;
        if(j==strlen(b))
            j=0; // found
    }
    if(f==1)
        cout<<cnt<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}

