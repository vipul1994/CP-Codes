/*input
3
-7 1
5 2
8 2
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

ill a[200010][2];

int main() {
    int n;
    S(n);

    F(i, 0, n) {
        Sl(a[i][0]);
        Sl(a[i][1]);
    }

    ill low = -2000000000;
    ill high = 2000000000;

    if (a[0][1] == 1) {
        low = 1900;
    } else {
        high = 1899;
    }

    int flag = 0;

    ill max_score = -2000000000;
    ill max_start = -2000000000;

    while (low <= high) {
        flag = 0;

        ill mid = (low + high) / 2;
        ill score = mid;

        F(i, 0, n) {
            if (a[i][1] == 1) {
                if (mid >= 1900) {
                    mid += a[i][0];
                } else {
                    flag = -1;
                    break;
                }
            } else {
                if (a[i][1] == 2) {
                    if (mid <= 1899) {
                        mid += a[i][0];
                    } else {
                        flag = -2;
                        break;
                    }
                }
            }
        }

        if (flag == -1) {
            low = score + 1;
        } else if (flag == -2) {
            high = score - 1;
        } else {
            max_score = max(max_score, mid);
            max_start = max(max_start, score);
            low = score + 1;
        }
    }


    if (max_score == -2000000000) {
        cout << "Impossible" << endl;
    } else if (max_start == 2000000000) {
        cout << "Infinity" << endl;
    } else {
        cout << max_score << endl;
    }

    return 0;
}