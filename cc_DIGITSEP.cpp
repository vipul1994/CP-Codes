/*input
*/

/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<double,double>
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

int n;
string s;
int m, x, y;

int dp[20][20];

int str2num(string s) {
    int len = s.size();
    int num = 0;
    F(i, 0, len) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

int dfs(int index, int last, int sep) {
    if (index == n - 1) {
        if (sep < x || sep > y || (index - (last + 1) + 1) > m) {
            dp[index][last][sep] = -1;
            return -1;
        }
        string ss = s.substr(last + 1, index - (last + 1) + 1);
        int num = str2num(ss);
        return num;
    }
}

int main() {
    int t;
    S(t);
    while (t--) {
        cin >> n >> s >> m >> x >> y;
        M(dp, -1);
        int ans = dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}