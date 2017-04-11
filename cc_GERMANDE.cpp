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

int a[1000010];
int cum[1000010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int o1, o2;
        cin >> o1 >> o2;
        int flag = 0;
        int n = o1 * o2;

        cum[0] = 0;
        F(i, 1, n + 1) {
            S(a[i]);
            if (a[i] == 0) { a[i] = -1; }
            cum[i] = cum[i - 1] + a[i];
        }

        F(i, 1, o2 + 1) {
            int index = i;
            int counter = 0;
            F(j, 1, o1 + 1) {
                if (index + o2 - 1 <= n) {
                    // cout << "simple " << cum[index + o2 - 1] - cum[index - 1] << endl;
                    if (cum[index + o2 - 1] - cum[index - 1] > 0) {
                        counter++;
                    }
                } else if (index + o2 - 1 > n) {
                    // cout << "hard " << cum[n] - cum[index - 1] + cum[i - 1] << endl;

                    if ((cum[n] - cum[index - 1] + cum[i - 1] > 0)) {
                        counter++;
                    }
                }
                index += o2;
            }
            if (counter > o1 / 2) {
                cout << 1 << endl;
                flag = 1;
                break;
            }
        }

        if (flag) {
            continue;
        }
        cout << 0 << endl;
    }
    return 0;
}	