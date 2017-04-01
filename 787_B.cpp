/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
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


int main() {
    int n, m;
    cin >> n >> m;
    int check = 0;
    F(i, 0, m) {
        int k;
        cin >> k;
        set<int> s;
        int flag = 0;
        F(j, 0, k) {
            int x;
            cin >> x;
            if (flag == 0 && s.count(-1 * x) == 1) {
                s.insert(x);
                flag = 1;
            } else {
                s.insert(x);
            }
        }
        if (flag == 0) {
            check = 1;
        }
    }
    if (check == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}