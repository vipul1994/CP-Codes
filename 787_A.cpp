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
#define INF (ill)1e18

int main() {
    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;
    ill ans = INF;
    F(i, 0, 100010) {
        if ((b - d + i * a) >= 0 && (b - d + i * a) % c == 0) {
            ans = min(ans, (ill) (b + i * a));
            break;
        }
    }
    F(i, 0, 100010) {
        if ((d - b + i * c) >= 0 && (d - b + i * c) % a == 0) {
            ans = min(ans, (ill) (d + i * c));
            break;
        }
    }
    if (ans != INF) {
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}