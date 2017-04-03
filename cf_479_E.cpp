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
#define MOD (ill)1e9 + 7


int n, a, b, k;
ill dp[5010][5010];

ill dfs(int a, int k)
{
    if (dp[a][k] != -1) {return dp[a][k];}
    cout << a << " " << k << endl;
    if (k == 0) {
        dp[a][k] = 1;
        return 1;
    }
    int diff = abs(b - a);
    int start = max(1, a - (diff - 1));
    int last = min(n, a + (diff - 1));
    ill ans = 0;
    F(i, start, last + 1) {
        if (i == a || (abs(b - i) == 1 && k - 1 != 0)) { continue;}
        ans += dfs(i, k - 1);
        ans %= MOD;
    }
    dp[a][k] = ans;
    return ans;
}


int main() {
    M(dp, -1);
    cin >> n >> a >> b >> k;
    ill ans = dfs(a, k);
    cout << ans << endl;
    return 0;
}