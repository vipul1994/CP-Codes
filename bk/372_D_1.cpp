/*input
*/
/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<ill,ill>
#define pwi pair<ill,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FB(i,a,n) for(int i=(a);i>=(n);--i)
#define FI(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define Sf(x) scanf("%f",&x)
#define Sd(x) scanf("%lf",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fi first
#define se second
#define INF 1e17

vector<int> graph[1010];
vector<pii> edges;
set<pii> sp_edges;
ill weights[1010][1010];
int parent[1010];
set<pii> path;

ill dijkstra(int src, int dest, int n) 
{

	priority_queue< pwi, vector <pwi> , greater<pwi>> pq;
	vector<ill> dist(n, INF); 
	M(parent, -1);

    dist[src] = 0;
	pq.push(pwi(0, src));

	while (!pq.empty()) {
		int u = pq.top().se;
		path.insert(pii(parent[u], u));
		pq.pop();

		if (u == dest) {
			break;
		}

		int len = graph[u].size();
		F(i, 0, len) {
			int v = graph[u][i];
			ill w = weights[u][v];
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.push(pii(dist[v], v));
			}
		}
	}

	return dist[dest];
}


int main()
{	
    int n, m, s, t;
    ill l;
    cin >> n >> m >> l >> s >> t;

    M(weights, -1);
    F(i, 0, m) {
    	int u, v;
    	ill w;
    	cin >> u >> v >> w;
    	graph[u].pb(v);
    	graph[v].pb(u);
    	weights[u][v] = w;
    	weights[v][u] = w;
    	edges.pb(pii(u, v));
    	if (w == 0) {
    		sp_edges.insert(pii(u, v));
    	}
    }

    for (auto& e: sp_edges) {
    	int u = e.fi;
    	int v = e.se;
    	weights[u][v] = weights[v][u] = INF;
    }
    path.clear();
    if (dijkstra(s, t, n) < l) {
    	cout << "NO" << endl;
    	return 0;
    } 


	for (auto& e: sp_edges) {
    	int u = e.fi;
    	int v = e.se;
    	weights[u][v] = weights[v][u] = 1;
    }
    path.clear();
    if (dijkstra(s, t, n) > l) {
    	cout << "NO" << endl;
    	return 0;
    } 

    cout << "YES" << endl;
    set<pii> final_path;
    for (auto& e: sp_edges) {
    	int u = e.fi;
    	int v = e.se;
    	if (path.count(pii(u, v)) == 1 || 
    		path.count(pii(v, u)) == 1) {
    		final_path.insert(pii(u, v));
    		continue;
    	}
		weights[u][v] = weights[v][u] = INF;
    }

    for (auto& e: final_path) {
		int u = e.fi;
    	int v = e.se;
    	if (u == -1) {
    		continue;
    	}
    	ill min_path = dijkstra(s, t, n);
    	if (min_path < l && u != -1) {
    		weights[u][v] = weights[v][u] = 1 + (l - min_path);
    	} else {
    		break;
    	}
    }

    for (auto& e: edges) {
    	cout << e.fi << " " << e.se << " " << weights[e.fi][e.se] << endl;
    }
    return 0;
}