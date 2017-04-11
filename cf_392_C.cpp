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

ill a[110][110];

int main() {
    M(a, 0);
    ill n, m, k, x, y;
    Sl(n);
    Sl(m);
    Sl(k);
    Sl(x);
    Sl(y);

    ill one_round = 0;
    if (n == 1) {
        one_round = m;
    } else {
        one_round = (2 * m) + (2 * (n - 2) * m);
    }

    ill turns = k / one_round;
    ill rem = k % one_round;

    F(i, 1, m + 1) {
        a[1][i] = turns;
        a[n][i] = turns;
    }

    F(i, 2, n) {
        F(j, 1, m + 1) {
            a[i][j] = 2 * turns;
        }
    }

    F(i, 1, n + 1) {
        if (rem == 0) {
            break;
        }
        F(j, 1, m + 1) {
            if (rem == 0) {
                break;
            }
            a[i][j] += 1;
            rem -= 1;
        }
    }

    FB(i, n - 1, 2) {
        if (rem == 0) {
            break;
        }
        F(j, 1, m + 1) {
            if (rem == 0) {
                break;
            }
            a[i][j] += 1;
            rem -= 1;
        }
    }
    ill maxi = 0;
    ill mini = 1000000000000000010;
    F(i, 1, n + 1) {
        F(j, 1, m + 1) {
            mini = min(mini, a[i][j]);
            maxi = max(maxi, a[i][j]);
        }
    }

    cout << maxi << " " << mini << " " << a[x][y] << endl;
    return 0;
}