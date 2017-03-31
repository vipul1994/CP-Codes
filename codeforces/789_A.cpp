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

ill w[100010];

int main() {
    ill n, k;
    cin >> n >> k;

    F(i, 0, n) {
        cin >> w[i];
    }

    ill days = 0;

    F(i, 0, n) {
        if (w[i] < 0) { continue; }
        ill temp_days = w[i] / (2 * k);
        ill rem = w[i] % (2 * k);
        if (rem > k) {
            temp_days++;
        } else if (rem > 0 && rem <= k) {
            temp_days++;
            if (i < n - 1) {
                w[i + 1] -= k;
            }
        }
        days += temp_days;
    }

    cout << days << endl;
    return 0;
}