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
#define debug(i, sz, x) F(i,0,sz){cout<<x[i].fi + x[i].se<<" ";}cout<<endl
#define fi first
#define se second
#define INF 1e18

vector<pii> V;

struct less_than_key
{
    inline bool operator() (const pii& pair1, const pii& pair2)
    {
        return (pair1.fi + pair1.se < pair2.fi + pair2.se);
    }
};


int main() {
    int n;
    cin >> n;
    F(i, 0, n) {
        ill x;
        ill w;
        cin >> x >> w;
        V.pb(pii(x, w));
    }
    sort(V.begin() , V.end(), less_than_key());
//    debug(i, V.size(), V);
    int last = 0;

    int ans = 1;
    F(i, 1, n) {
        if (V[i].fi - V[i].se >= V[last].fi + V[last].se) {
            last = i;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}