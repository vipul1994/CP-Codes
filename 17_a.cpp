/*input
*/

/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pis pair<int,string>
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

std::vector<ill> usb;
std::vector<ill> ps;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    F(i, 0, n) {
        ill cost;
        string port;
        cin >> cost >> port;
        if (port == "USB") { usb.pb(cost); }
        if (port == "PS/2") { ps.pb(cost); }
    }

    sort(usb.begin(), usb.end());
    sort(ps.begin(), ps.end());

    int usb_used = min(a, int(usb.size()));
    int ps_used = min(b, int(ps.size()));
    int both_used = max(0, min(c, int(usb.size()) + int(ps.size()) - usb_used - ps_used));

    ill cost = 0;
    F(i, 0, usb_used) {
        cost += usb[i];
    }

    F(i, 0, ps_used) {
        cost += ps[i];
    }

    std::vector<int> both;
    F(i, usb_used, usb.size()) {
        both.pb(usb[i]);
    }
    F(i, ps_used, ps.size()) {
        both.pb(ps[i]);
    }

    sort(both.begin(), both.end());
    F(i, 0, both_used) {
        cost += both[i];
    }

    int total = usb_used + ps_used + both_used;
    cout << total << " " << cost << endl;

    return 0;
}