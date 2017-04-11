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
    string s;
    cin >> s;

    int len = s.size();

    string color = "RBYG";
    int flag = 1;

    int ans[4];
    M(ans, 0);

    while (flag) {
        flag = 0;
        F(i, 0, len - 4 + 1) {
            int check[4];
            M(check, 0);
            int index = -1;
            int counter = 0;
            F(j, i, i + 4) {
                if (s[j] == 'R') { check[0] = 1; }
                if (s[j] == 'B') { check[1] = 1; }
                if (s[j] == 'Y') { check[2] = 1; }
                if (s[j] == 'G') { check[3] = 1; }
                if (s[j] == '!') {
                    counter++;
                    index = j;
                }
            }

            if (counter == 1) {
                F(j, 0, 4) {
                    if (check[j] == 0) {
                        s[index] = color[j];
                        ans[j]++;
                        flag = 1;
                    }
                }
            }
        }
    }

    F(i, 0, 4) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}