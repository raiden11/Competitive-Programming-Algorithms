
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define lf long double
#define in(x) scanf("%d",&x);
#define sz(x) ((int)x.size())
#define lld l64d
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rrep1(i,a,b) for(i=a;i>=b;i--)
#define stlfor(i,t) for(auto i =t.begin();i!=t.end();i++)
#define fr freopen("x.txt","r",stdin)
#define frc freopen("y.txt","w",stdout)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;
#define pset(n) fixed<<showpoint<<setprecision(n)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 2000006;
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

const int MAXS = 500;
const int MAXC = 26;

// taken from gfg
int f[MAXS], g[MAXS][MAXC];
bitset<10000> out[MAXS];

int build(string arr[], int k)
{
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);
    int states = 1;
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
            currentState = g[currentState][ch];
        }
        out[currentState][i] = 1;
    }

    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;

    memset(f, -1, sizeof f);

    queue<int> q;
    for (int ch = 0; ch < MAXC; ++ch)
    {
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (q.size())
    {
        int state = q.front();
        q.pop();
        for (int ch = 0; ch <= MAXC; ++ch)
        {
            if (g[state][ch] != -1)
            {
                int failure = f[state];

                while (g[failure][ch] == -1)
                    failure = f[failure];

                failure = g[failure][ch];
                f[g[state][ch]] = failure;
                out[g[state][ch]] |= out[failure];
                q.push(g[state][ch]);
            }
        }
    }
    return states;
}

// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.

int findNextState(int currentState, char nextInput)
{
    int answer = currentState;
    int ch = nextInput - 'a';

    // If goto is not defined, use failure function
    while (g[answer][ch] == -1)
        answer = f[answer];

    return g[answer][ch];
}

// This function finds all occurrences of all array words
// in text.
void searchWords(string arr[], int k, string text)
{
    // Preprocess patterns.
    // Build machine with goto, failure and output functions
    int states = build(arr, k);
//    cout<<states<<endl;
//    for(int i=0;i<states;i++)
//    {
//        for(int ch=0;ch<MAXC;ch++)
//            cout<<g[i][ch]<<" ";
//        cout<<endl;
//    }

//    for(int i=0;i<states;i++)
//    {
//        cout<<f[i]<<" ";
//    }

//    for(int i=0;i<states;i++)
//        cout<<i<<" "<<out[i]<<endl;
//    cout<<endl;
    // Initialize current state
    int currentState = 0;

    // Traverse the text through the nuilt machine to find
    // all occurrences of words in arr[]
    for (int i = 0; i < text.size(); ++i)
    {
        currentState = findNextState(currentState, text[i]);

        // If match not found, move to next state
        if (out[currentState] == 0)
             continue;

        // Match found, print all matching words of arr[]
        // using output function.
        for (int j = 0; j < k; ++j)
        {
            if (out[currentState][j]==1)
            {
                cout << "Word " << arr[j] << " appears from "
                     << i - arr[j].size() + 1 << " to " << i << endl;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        string arr[] = {"bc", "abc", "ta", "c"};
        string text = "tabcbc";
        int k = sizeof(arr)/sizeof(arr[0]);
        searchWords(arr, k, text);

        return 0;
    }
    return 0;
}

