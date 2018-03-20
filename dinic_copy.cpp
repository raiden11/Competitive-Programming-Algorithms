
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

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }


struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};


struct Dinic {

	int N;
	vector<Edge> E;
	vector<vector<int> > g;
	vector<int> d, pt;

	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

	void AddEdge(int u, int v, ll cap) {
		if (u != v) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}

	bool BFS(int S, int T) {
		queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k: g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}

	ll DFS(int u, int T, ll flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1) {
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = DFS(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	ll MaxFlow(int S, int T) {
		ll total = 0;
		while (BFS(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = DFS(S, T))
				total += flow;
		}
		return total;
	}
};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {
        int n,m;
        int u,v;
        ll c;
        cin>>n>>m;
        Dinic dinic(n);
        rep(i,m)
        {
             cin>>u>>v>>c;
            dinic.AddEdge(u-1, v-1, c);
            dinic.AddEdge(v-1, u-1, c);
        }

        cout<<dinic.MaxFlow(0, n-1)<<endl;
        for(auto & e:dinic.E )
            if(e.flow>=0)
                cout<<e.u<<" "<<e.v<<" "<<e.flow<<endl;

    }
    return 0;
}
