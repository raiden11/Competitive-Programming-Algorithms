// n queens
//backtrack

#include<stdio.h>
using namespace std;
int n;
int check(int a[9][9],int x,int y)
{
    int i=x-1,j=y;
    while(i>=0)
    {
        if(a[i][y]==1)
            return 0;
        i--;
    }
    i=x-1;
    j=y-1;
    while(i>=0&&j>=0)
    {
        if (a[i][j]==1)
            return 0;
        i--;
        j--;
    }
    i=x-1;
    j=y+1;
    while(i>=0&&j<n)
    {
        if(a[i][j]==1)
            return 0;
        i--;
        j++;
    }
    return 1;
}

void out(int a[9][9],int x,int y)
{
    int i,j;
    a[x][y]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
                printf("Q\t");
            else
                printf("-\t");
        }
        printf("\n");
    }
    a[x][y]=0;
}
void bt(int a[9][9],int x)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(x==n-1)
        {
            if(check(a,x,j)==1)
            {
                out(a,x,j);
                printf("\n");
            }
        }
        else
        {
            a[x][j]=1;
            if(check(a,x,j))
                bt(a,x+1);
            a[x][j]=0;
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d",&n)>0)
    {
        int a[9][9];
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
                a[i][j]=0;
        if(n>3)
            bt(a,0);
        else if(n==1)
            printf("Q\n");
        else
            printf("Not Possible\n");
    }
    return 0;
}
