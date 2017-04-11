/*input
16
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
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


int main() {
    int t;
    int m, n;

    S(t);

    F(i, 0, t) {
        S(n);
        m = n / 8;
        n = n % 8;
        if (n == 0) {
            n = 8;
            m = m - 1;
        }
        if (n == 1) {
            cout << 8 * m + 4 << "LB" << endl;
        }
        if (n == 2) {
            cout << 8 * m + 5 << "MB" << endl;
        }
        if (n == 3) {
            cout << 8 * m + 6 << "UB" << endl;
        }
        if (n == 4) {
            cout << 8 * m + 1 << "LB" << endl;
        }
        if (n == 5) {
            cout << 8 * m + 2 << "MB" << endl;
        }
        if (n == 6) {
            cout << 8 * m + 3 << "UB" << endl;
        }
        if (n == 7) {
            cout << 8 * m + 8 << "SU" << endl;
        }
        if (n == 8) {
            cout << 8 * m + 7 << "SL" << endl;
        }

    }
    return 0;
}