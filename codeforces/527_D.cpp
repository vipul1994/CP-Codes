/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
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
#define INF 1e18

vector<pii> V;


int main() {
    int n;
    cin >> n;
    F(i, 0, n) {
        ill x;
        ill w;
        cin >> x >> w;
        V.pb(pii(x, w));
    }
    sort(V.begin() , V.end());
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