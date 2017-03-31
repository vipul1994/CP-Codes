/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define ll long long int
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
#define INF 1e17

ill a[100010];
ill dp1[100010];
ill dp2[100010];

int main() {
    int n;
    cin >> n;
    F(i, 0, n) {
        Sl(a[i]);
    }

    F(i, 0, n - 1) {
        a[i] = abs(a[i] - a[i + 1]);
    }

    dp1[0] = -1 * INF; // negative
    dp2[0] = a[0];  // positive

    ill ans = dp2[0];
    F(i, 1, n - 1) {
        dp1[i] += dp2[i - 1] + -1 * a[i];
        dp2[i] += max(a[i], dp1[i - 1] + a[i]);
        ans = max(ans, dp1[i]);
        ans = max(ans, dp2[i]);
    }
//    debug(i, 6, dp1);
//    debug(i, 6, dp2);

    cout << ans << endl;
    return 0;
}