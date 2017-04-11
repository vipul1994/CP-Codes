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

int a[30];
int matrix[400][400];
int dp[400][400][8][6];
int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    M(matrix, -1);
    M(dp, -1);

    int n;
    S(n);

    F(i, 0, n) {
        S(a[i]);
    }

    queue<pii > index;
    queue<int> slope;

    index.push(pii(200, 200));
    slope.push(2);
    dp[200][200][2][a[0]] = 0;
    matrix[200][200] = 0;

    int N = 0;
    while (!index.empty()) {
        int nodes = (int) index.size();
        int depth = a[N];
        F(i, 0, nodes) {
            pii coordinate = (pair<int, int> &&) index.front();
            index.pop();
            int m = slope.front();
            slope.pop();
            int ncx = coordinate.fi;
            int ncy = coordinate.se;

//            cout << ncx << " " << ncy << endl;
            F(j, 1, depth) {
                ncx += dxx[m];
                ncy += dyy[m];
//                cout << ncx << " " << ncy << endl;
                matrix[ncx][ncy] = 0;
            }
            if (N + 1 == n) {
                continue;
            }
            int fcx = ncx;
            int fcy = ncy;
            ncx = fcx + dxx[(m + 1) % 8];
            ncy = fcy + dyy[(m + 1) % 8];

            if (dp[ncx][ncy][(m + 1) % 8][a[N + 1]] == -1) {
                dp[ncx][ncy][(m + 1) % 8][a[N + 1]] = 0;
                index.push(pii(ncx, ncy));
                slope.push((m + 1) % 8);
                matrix[ncx][ncy] = 0;
            }

            ncx = fcx + dxx[(m + 7) % 8];
            ncy = fcy + dyy[(m + 7) % 8];

            if (dp[ncx][ncy][(m + 7) % 8][a[N + 1]] == -1) {
                dp[ncx][ncy][(m + 7) % 8][a[N + 1]] = 0;
                index.push(pii(ncx, ncy));
                slope.push((m + 7) % 8);
                matrix[ncx][ncy] = 0;
            }
        }
        N++;
    }

    int ans = 0;
    F(i, 0, 400) {
        F(j, 0, 400) {
            if (matrix[i][j] == 0) { ans++; }
        }
    }

    cout << ans << endl;
    return 0;
}