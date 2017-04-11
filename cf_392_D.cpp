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
    ill n;
    string k;

    cin >> n >> k;

    ill x = n;
    ill counter = 0;
    while (x) {
        x /= 10;
        counter++;
    }


    ill ans = 0;
    ill pos = 1;
    ill num = 0;
    int index = 0;

    FB(i, k.size() - 1, 0) {
        ill last = num;
        num = pow(10, index) * (k[i] - '0') + num;
        index++;


        if (index > counter || num >= n) {
            ans += last * pos;
            pos *= n;

            index = 0;
            num = 0;

            i++;
        }
    }
    ans += num * pos;
    cout << ans << endl;
    return 0;
}