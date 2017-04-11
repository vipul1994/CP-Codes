/*input
2
7
13 2 8 6 3 1 9
6
1 2 2 3 3 1
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

#define MAX 10000010
ill rooms[100010];
bool check[MAX];
ill min_factor[MAX];
ill max_room[MAX];

int sieve() {
    M(check, 0);
    for (ill i = 2; i < MAX; i += 2) { min_factor[i] = 2; }
    for (ill i = 3; i < MAX; i += 2) {
        if (!check[i]) {
            min_factor[i] = i;
            check[i] = true;
            for (ill j = i; i * j < MAX; j += 2) {
                if (!check[i * j]) {
                    check[i * j] = true;
                    min_factor[i * j] = i;
                }
            }
        }
    }
}

int main() {
    sieve();
    // debug(i, 30, min_factor);
    int t;
    S(t);
    F(i, 0, t) {
        ill ans = 1;
        M(max_room, 0);
        int n;
        S(n);
        F(j, 0, n) {
            S(rooms[j]);
        }
        FB(j, n - 1, 0) {
            V(ill) prime_f;
            ill k = rooms[j];
            while (k > 1) {
                prime_f.pb(min_factor[k]);
                ill min_f = min_factor[k];
                while (k % min_f == 0) {
                    k /= min_f;
                }
            }
            int len = prime_f.size();
            ill max_r = 1;
            F(l, 0, len) {
                max_r = max(max_r, max_room[prime_f[l]] + 1);
            }
            F(l, 0, len) {
                max_room[prime_f[l]] = max_r;
                ans = max(ans, max_room[prime_f[l]]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}