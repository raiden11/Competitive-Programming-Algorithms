//heaps data structure
//heap_sort

#include<bits/stdc++.h>

using namespace std;

#define inf 1000000000
#define mod 1000000007
#define ll long long int
#define in(x) scanf("%d",&x);
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const double pi(3.14159265358979);

/*
Heaps are a data structure that is used as garbage collector in java and lisp
max heap: where a[parent]>=a[child];
min heap: where a[parent]<=a[child];
used in priority queues
*/

/*
Heapsort sorts the array in place and takes O(nlogn)time
max heap : here the max element is at root
    we swap root with last element of heap
    then again max_heapify while decreasing the size of heap by 1
    max element will come at root position ...
    repeat
*/

int a[10000],heap[10000],n,heapsz;
void max_heapify(int node)                     // heapify function heap me jo choti nodes hoti hain unhe niche lekar jaata h
{                                              // par badi wali node ko upar lekar ni aata
    int large = node;
    if(2*node<=heapsz&&heap[2*node]>heap[large])
        large=2*node;
    if(2*node+1<=heapsz&&heap[2*node+1]>heap[large])
        large=2*node+1;
    if(large!=node)
    {
        swap(heap[node],heap[large]);
        max_heapify(large);
    }

}
//note that heap size and array size(n) would be same

void heapsort()
{
    for(i=n;i>=2;i--)
    {
        swap(heap[i],heap[1]);
        heapsz--;
        max_heapify(1);
    }
}

int main()
{
    int i,j,m,ans;
    in(n)
    heapsz=n;
    for(i=1;i<=n;i++)
        in(heap[i])
    for(i=n/2;i>=1;i--)
        max_heapify(i);
    for(i=1;i<=n;i++)
        cout<<heap[i]<<" ";         // heap array after build function
    cout<<endl;
    heapsort();
    for(i=1;i<=n;i++)
        cout<<heap[i]<<" ";         // final sorted array
    cout<<endl;
    return 0;
}
