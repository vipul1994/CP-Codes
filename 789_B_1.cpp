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
#define INF 1e18

ill a[100010];
ill b[100010];

int main() {
    ill b1, q, l, m;
    cin >> b1 >> q >> l >> m;


    F(i, 0, m) {
        cin >> a[i];
    }

    if (abs(b1) > l) {
        cout << "0" << endl;
        return 0;
    }
    if (abs(b1) == 0) {
        F(i, 0, m) {
            if (a[i] == b1) {
                cout << "0" << endl;
                return 0;
            }
        }
        cout << "inf" << endl;
        return 0;
    }
    if (q == 0) {
        int f1 = 0, f2 = 0;
        F(i, 0, m) {
            if (a[i] == b1) {
                f1 = 1;
            }
            if (a[i] == 0) {
                f2 = 1;
            }
        }
        if (f1 == 1 && f2 == 1) {
            cout << "0" << endl;
            return 0;
        }
        if (f2 == 1) {
            cout << "1" << endl;
            return 0;
        }
        cout << "inf" << endl;
        return 0;
    }
    if (q == 1) {
        int f1 = 0;
        F(i, 0, m) {
            if (a[i] == b1) {
                cout << "0" << endl;
                return 0;
            }
        }
        cout << "inf" << endl;
        return 0;
    }
    if (q == -1) {
        int f1 = 0, f2 = 0;
        F(i, 0, m) {
            if (a[i] == b1) {
                f1 = 1;
            }
            if (a[i] == -1 * b1) {
                f2 = 1;
            }
        }
        if (f1 == 1 && f2 == 1) {
            cout << "0" << endl;
            return 0;
        }
        cout << "inf" << endl;
        return 0;
    }

    ill a1 = b1;
    ill r = q;
    ill counter = 0;
    while (abs(a1) <= l) {
        b[counter] = a1;
        counter++;
        a1 *= r;
    }

    sort(a, a + m);
    ill ans = counter;
    F(i, 0, m) {
        if (i != 0 && a[i - 1] == a[i]) { continue; }
        F(j, 0, counter) {
            if (a[i] == b[j]) { ans--; }
        }
    }

    cout << ans << endl;
    return 0;
}