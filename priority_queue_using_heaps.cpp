//priority queue implementation
//using maximum heapsort
//clrs

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

int heap[10000],index[10000];
int heapsz;

//insertion,max retrieval nd deletion,increase of key happens in log(n) time
//max retrieval happens in O(1) time

void heapify(int no)                    // heapify function heap me jo choti nodes hoti hain unhe niche lekar jaata h
{                                       // par badi wali node ko upar lekar ni aata
    int child=2*no;
    int large=no;
    if(child<=heapsz&&heap[child]>heap[large])
        large=child;
    if(child+1<=heapsz&&heap[child+1]>heap[large])
        large = child+1;
    if(large!=no)
    {
        swap(heap[no],heap[large]);
        swap(index[no],index[large]);
        heapify(large);
    }
}

int main()
{
    int i,n,m,no,j,ans,key,pos,idx;
    heapsz=0;
    printf("1. Insert element\n2. Print max\n3. Extract and print max\n4. Increase key\n0. Exit\n");
    while(true)
    {
        in(no)
        switch(no)
        {
            case 0:
                    return 0;
            case 1:
                    printf("Enter index of element and its key \n");
                    scanf("%d%d",&idx,&key);
                    heapsz++;
                    index[heapsz]=idx;
                    heap[heapsz]=key;
                    /*heapify(1);
                        consider case when 1 2 3 elements are 57 45 and 23 and next added elements is 4 500
                        if we call heapify(1),
                            both 2 nd 3 of heap are lesser than heap, so it wont swap
                        Hence our method would fail
                        Therefore we do this:
                    */
                    i=heapsz;
                    while(i>1&&heap[i/2]<heap[i])
                    {
                        swap(heap[i/2],heap[i]);
                        swap(index[i/2],index[i]);
                        i=i/2;
                    }
                    break;
            case 2:
                    printf("Max element is %d having key: %d\n",index[1],heap[1]);
                    break;
            case 3:
                    printf("Max element is %d having key: %d\n",index[1],heap[1]);
                    swap(heap[1],heap[heapsz]);
                    swap(index[1],index[heapsz]);
                    heapsz--;
                    heapify(1);
                    break;
            case 4:
                    printf("Enter index of element and new value of key\n");
                    scanf("%d%d",&idx,&key);
                    for(i=1;i<=heapsz;i++)         // i need a better method for this , this is o(n)
                        if(index[i]==idx)          // searching for index to be modified in the array.
                            break;                 // think about log(n)...what about a bst ??
                    heap[i]=key;
                    while(i>1)
                    {
                        if(heap[i/2]<heap[i])
                        {
                            swap(heap[i],heap[i/2]);
                            swap(index[i],index[i/2]);
                            i=i/2;
                        }
                        else
                            break;
                    }

                    break;
        }
    }
    return 0;
}
