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

ill a1[100010];
ill b1[100010];

int main() {
    ill b, q, l, m;
    cin >> b >> q >> l >> m;

    F(i, 0, m) {
        cin >> a1[i];
    }

    sort(a1, a1 + m);

    if (b == 0 || q == 0) {
        F(i, 0, m) {
            if (a1[i] == 0) {
                cout << "0" << endl;
                return 0;
            }
        }
        cout << "inf" << endl;
        return 0;
    }
    if (q == 1) {
        if (abs(b) <= l) {
            F(i, 0, m) {
                if (a1[i] == b) {
                    cout << "0" << endl;
                    return 0;
                }
            }
            cout << "inf" << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    if (q == -1) {
        if (abs(b) <= l) {
            int flag1 = 0;
            int flag2 = 0;
            F(i, 0, m) {
                if (a1[i] == b) {
                    flag1 = 1;
                }
                if (a1[i] == -1 * b) {
                    flag2 = 1;
                }
            }
            if (flag1 == 1 && flag2 == 1) {
                cout << "0" << endl;
            } else {
                cout << "inf" << endl;
            }
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    ill a = abs(b);
    ill r = abs(q);

    int index = 0;
    while (a <= l) {
        index++;
        a *= r;
    }

    a = b;
    r = q;
    F(i, 0, index) {
        b1[i] = a * r;
        a *= r;
    }

    ill counter = index;
    F(i, 0, m) {
        if (i != 0 && a1[i - 1] == a1[i]) {
            continue;
        }
        if (abs(a1[i]) <= l) {
            F(j, 0, index) {
                if (a1[i] == b1[j]) {
                    counter--;
                    break;
                }
            }
        }
    }

    cout << counter << endl;
    return 0;
}