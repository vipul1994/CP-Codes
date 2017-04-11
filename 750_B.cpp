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
    int n;
    S(n);

    int pos = 0;
    int flag = 0;

    F(i, 0, n) {
        int dis;
        string dir;
        cin >> dis >> dir;

        if (dir == "North") {
            if (pos - dis < 0) {
                flag = -1;
            }
            pos -= dis;

        } else if (dir == "South") {
            if (pos + dis > 20000) {
                flag = -1;
            }
            pos += dis;

        } else if (dir == "East" || dir == "West") {
            if (pos == 0 || pos == 20000) {
                flag = -1;
            }
        }
    }

    if (flag == -1) {
        cout << "NO" << endl;
        return 0;
    }
    if (pos == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}