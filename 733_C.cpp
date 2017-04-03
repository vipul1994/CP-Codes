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

ill a[510];
ill b[510];
int indices[510];

int main() {

    int n;
    S(n);
    F(i, 0, n) {
        Sl(a[i]);
    }
    int k;
    S(k);
    F(i, 0, k) {
        Sl(b[i]);
    }

    int index1 = 0;
    int index2 = 0;
    int pre_index = -1;
    ill pre_sum = 0;
    ill mini = INF;
    ill maxi = 0;
    while (index1 < n) {
        if (index2 == k) {
            cout << "NO" << endl;
            return 0;
        }

        mini = min(mini, a[index1]);
        maxi = max(maxi, a[index1]);
        pre_sum += a[index1];

        if (pre_sum == b[index2]) {
            if (mini == maxi && index1 - pre_index != 1) {
                cout << "NO" << endl;
                return 0;
            }
            indices[index2] = index1;
            ++index2;
            pre_index = index1;
            pre_sum = 0;
            mini = INF;
            maxi = 0;
        } else if (pre_sum > b[index2]) {
            cout << "NO" << endl;
            return 0;
        }
        ++index1;
    }

    if (index2 != k) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    int start_index = 0;
    pre_index = 0;
    F(i, 0, k) {
        vector<ill> V(a + start_index, a + indices[i] + 1);
        start_index = indices[i] + 1;

        while (V.size() != 1) {
            ill maxi = 0;
            ill maxind = -1;
            F(j, 0, V.size()) {
                if (maxi < V[j]) {
                    if (j != 0 && V[j] != V[j - 1]) {
                        maxi = max(maxi, V[j]);
                        maxind = j;
                    } else if (j != V.size() - 1 && V[j] != V[j + 1]) {
                        maxi = max(maxi, V[j]);
                        maxind = j;
                    }
                }
            }
            if (maxind != V.size() - 1 && V[maxind + 1] != V[maxind]) {
                cout << i + maxind + 1 << " R" << endl;
                V[maxind + 1] += V[maxind];
                V.erase(V.begin() + maxind);
            } else {
                cout << i + maxind + 1 << " L" << endl;
                V[maxind - 1] += V[maxind];
                V.erase(V.begin() + maxind);
            }
        }
    }
    return 0;
}