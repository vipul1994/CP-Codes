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

int main() {
    int t;
    int c, d, l;
    cin >> t;

    F(i, 0, t) {
        cin >> c >> d >> l;
        if (l % 4) {
            cout << "no" << endl;
            continue;
        }

        int species = l / 4;
        int min_cat = (c - 2 * d >= 0) ? (c - 2 * d) : 0;

        if (species > c + d || species < d + min_cat) {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }
    return 0;
}