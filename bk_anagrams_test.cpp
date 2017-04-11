/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define psi pair<string,int>
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
#define debug(i, sz, x) F(i,0,sz){cout<<x[i].fi<<"," << x[i].se << " ";}cout<<endl
#define fi first
#define se second
#define INF 1e18

map<string, set<int>> ans;

int main() {
    vector<string> input;
    vector<psi > dup;
    int n;
    cin >> n;

    F(i, 0, n) {
        string a;
        cin >> a;
        input.pb(a);
        sort(a.begin(), a.end());
        dup.pb(psi(a, i));
    }

    sort(dup.begin(), dup.end());

//    debug(i, dup.size(), dup);

    F(i, 0, n - 1) {
        string a = dup[i].fi;
        string b = dup[i + 1].fi;
        if (a.compare(b) != 0) { continue; }
        if (ans.find(a) == ans.end()) {
            set<int> s;
            s.insert(dup[i].se);
            s.insert(dup[i + 1].se);
            ans[a] = s;
        } else {
            ans[a].insert(dup[i].se);
            ans[a].insert(dup[i + 1].se);
        }
    }

    auto it = ans.begin();
    FI(it, ans) {
        set<int> s = it->second;
        auto it1 = s.begin();
        FI(it1, s) {
            cout << input[*it1] << " ";
        }
        cout << endl;
    }

    return 0;
}