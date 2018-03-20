#include<bits/stdc++.h>
using namespace std;

struct event
{
    int arrival_time;
    int burst_time;
    int completion_time;
    int index;
    int system_mila;
};

bool comp(event a,event b)
{
    return a.burst_time<b.burst_time;
}

event all[100];

struct result
{
    int waiting_time;
    int turn_around;
};
result ans[100];

int main()
{
    int n,i,j;
    cout<<"Enter no of processes:\n";
    cin>>n;
    cout<<"Enter arrival and burst time of all the processes: \n";
    for(i=0;i<n;i++)
    {
        cout<<"Process "<<i+1<<": ";
        cin>>all[i].arrival_time;
        cin>>all[i].burst_time;
        all[i].index = i;
    }

    sort(all, all+n, comp);

    int time=all[0].arrival_time;

    for(i=0;i<n;i++)
    {
        all[i].system_mila = time;
        time = time + all[i].burst_time;
        all[i].completion_time = time;
    }

    for(i=0;i<n;i++)
    {
        ans[all[i].index].turn_around = all[i].completion_time - all[i].arrival_time;
        ans[all[i].index].waiting_time = ans[all[i].index].turn_around - all[i].burst_time;
    }
    cout<<"\n\nResults:\nProcess\t\tTurn Around Time\t  Waiting Time\n";
    cout<<fixed<<showpoint<<setprecision(2);

    for(i=0;i<n;i++)
    {
        cout<<i+1<<fixed<<showpoint<<setprecision(2)<<"\t\t\t  "<<(double)ans[i].turn_around<<"\t\t\t"<<(double)ans[i].waiting_time<<endl;
    }
    return 0;
}

