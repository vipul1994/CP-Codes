/*input
*/

/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<ill,ill>
#define pb(x) push_back(x)
#define F(i, a, n) for(int i=(a);i<(n);++i)
#define FB(i, a, n) for(int i=(a);i>=(n);--i)
#define FI(it, x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define Sf(x) scanf("%f",&x)
#define Sd(x) scanf("%lf",&x)
#define M(x, i) memset(x,i,sizeof(x))
#define debug(i, sz, x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fi first
#define se second
#define INF 1e17

vector<pii > graph[1010];
vector<pii > original_graph[1010];
set<pii > edges;
int parent[1010];

int get_shortest_path(int src, int dest, int n) {
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    vector<ill> dist(n, INF);

    dist[src] = 0;
    pq.push(pii(0, src));

    while (!pq.empty()) {
        ill u = pq.top().se;
        pq.pop();

        if (u == dest) {
            break;
        }

        int len = graph[u].size();
        F(i, 0, len) {
            ill v = graph[u][i].fi;
            ill w = graph[u][i].se;
            if (w != 0 && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(pii(dist[v], v));
            }
        }
    }

    return dist[dest];
}

int main() {
    int n, m, s, t;
    ill l;

    cin >> n >> m >> l >> s >> t;
    F(i, 0, m) {
        ill u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(pii(v, w));
        graph[v].pb(pii(u, w));
        original_graph[u].pb(pii(v, w));
        if (w == 0) {
            edges.insert(pii(u, v));
        }
    }

    M(parent, -1);
    ill distance = get_shortest_path(s, t, n);
    if (distance < l) {
        cout << "NO" << endl;
        return 0;
    } else if (distance == l) {
        cout << "YES" << endl;
        F(i, 0, n) {
            int len = original_graph[i].size();
            F(j, 0, len) {
                ill node = original_graph[i][j].fi;
                ill w = original_graph[i][j].se;
                if (original_graph[i][j].se == 0) {
                    w = INF;
                }
                cout << i << " " << node << " " << w << endl;
            }
        }
        return 0;
    }

    F(i, 0, n) {
        int len = graph[i].size();
        F(j, 0, len) {
            if (graph[i][j].se == 0) {
                graph[i][j].se = 1;
            }
        }
    }
    M(parent, -1);
    distance = get_shortest_path(s, t, n);

    if (distance > l) {
        cout << "NO" << endl;
    } else if (distance == l) {
        cout << "YES" << endl;
        F(i, 0, n) {
            int len = original_graph[i].size();
            F(j, 0, len) {
                ill node = original_graph[i][j].fi;
                ill w = original_graph[i][j].se;
                if (original_graph[i][j].se == 0) {
                    w = 1;
                }
                cout << i << " " << node << " " << w << endl;
            }
        }
    } else {
        ill rem = l - distance;
        ill node = t;
        set<pii > change_edges;
        int special_vertice = -1;
        while (parent[node] != -1) {
            ill u = parent[node];
            ill v = node;
            node = u;
            if (edges.count(pii(u, v)) == 1) {
                if (special_vertice == -1) {
                    special_vertice = v;
                }
                change_edges.insert(pii(u, v));
            } else if (edges.count(pii(v, u)) == 1) {
                if (special_vertice == -1) {
                    special_vertice = u;
                }
                change_edges.insert(pii(v, u));
            }
        }
        cout << "YES" << endl;
        F(i, 0, n) {
            int len = original_graph[i].size();
            F(j, 0, len) {
                ill node = original_graph[i][j].fi;
                ill w = original_graph[i][j].se;
                if (change_edges.count(pii(i, node)) == 1 ||
                    change_edges.count(pii(node, i)) == 1) {
                    if (node == special_vertice) {
                        w = 1 + rem;
                    } else {
                        w = 1;
                    }
                } else if (edges.count(pii(i, node)) == 1 ||
                           edges.count(pii(node, i)) == 1) {
                    w = INF;
                }
                cout << i << " " << node << " " << w << endl;
            }
        }
        return 0;
    }

    return 0;
}