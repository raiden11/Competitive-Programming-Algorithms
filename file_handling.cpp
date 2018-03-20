#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fil;
    fil.open("example.txt");
    long long int i,j,lim = 5000;
    double crosslim=sqrt(lim);
    vector<int>s;
    vector<int>a;
    for(i=0;i<=5010;i++)
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
    fil<<"[";
    for(i=5;i<=2500;i+=4)
        if(s[i]==0)
            {
                fil<<i;
                fil<<", ";
            }
    fil<<"]";
    fil.close();
    char ch='a';
    ifstream f;
    f.open("example.txt");
    while(ch!=']')
    {
        f>>ch;
        if(ch!=',')
            cout<<ch;
        else
            cout<<endl;
    }
    f.close();
    return 0;
}
