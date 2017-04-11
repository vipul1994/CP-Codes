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

int a[6] = {0, 1, 2, 2, 1, 0};
int b[6] = {1, 0, 0, 1, 2, 2};
int c[6] = {2, 2, 1, 0, 0, 1};

int main() {
    ill n;
    cin >> n;
    ill x;
    cin >> x;

    if (a[n % 6] == x) {
        cout << 0 << endl;
    } else if (b[n % 6] == x) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}