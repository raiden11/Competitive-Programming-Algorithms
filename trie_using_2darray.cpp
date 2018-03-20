//tries
//strings
//2d array
//codeforces


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
#define inf 1000000000
#define mod 1000000007
#define ll long long
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)

struct node
{
    int word;
    int pre;
    int n;
};

node a[10000][26];

int main()
{
    int no,i,v=0,z,next=1;
    cout<<"1. enter word"<<endl<<"2. find prefix"<<endl<<"3. find word"<<endl;
    in(no);
    char s[100];
    while(no--)
    {
        v=0;
        scanf("%d",&z);
        if(z==1)
        {
            scanf("%s",&s);
            for(i=0;i<strlen(s);i++)
            {
                if(a[v][s[i]-97].n==0)
                    a[v][s[i]-97].n=next++;
                a[v][s[i]-97].pre++;
                v=a[v][s[i]-97].n;
            }

            a[v][s[i]-97].word++;
        }
        else if(z==2)
        {
            scanf("%s",&s);
            v=0;
            for(i=0;i<strlen(s);i++)
            {
                if(a[v][s[i]-97].n==0)
                {
                    cout<<0<<endl;
                    break;
                }
                if(i==strlen(s)-1)
                {
                    cout<<a[v][s[i]-97].pre<<endl;;
                    break;
                }
                v=a[v][s[i]-97].n;
            }
        }
        else
        {
            scanf("%s",&s);
            v=0;
            for(i=0;i<strlen(s);i++)
            {
                if(a[v][s[i]-97].n==0)
                    break;
                v=a[v][s[i]-97].n;

            }
            cout<<a[v][s[i]-97].word<<endl;
        }
    }
    return 0;
}
