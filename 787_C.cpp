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

vector<int> players[2];

// Loop -> 0 Lose -> 1 Win -> 2 Processing -> 3
// Rick -> 0 Morty -> 1

int dp[2][7010];
int n;

int dfs(int person, int index)
{
    if (index == 0) {
        dp[person][index] = 1;
        return 2;
    }
    if (dp[person][index] != -1) {
        if (dp[person][index] == 1) {
            return 2;
        } else if (dp[person][index] == 2) {
            return 1;
        } else {
            return dp[person][index];
        }
    }
    dp[person][index] = 3;
    int len = (int)(players[person].size());
    F(i, 0, len) {
        int val = dfs(1 - person, (index + players[person][i]) % n);
        if (val == 2) {
            dp[person][index] = 2;
            return 1;
        } else if (val == 0) {
            dp[person][index] = 0;
        }
    }
    if (dp[person][index] == 3) {
        dp[person][index] = 1;
        return 2;
    } else if (dp[person][index] == 0) {
        return 0;
    }
}

int main() {

    M(dp, -1);

    cin >> n;

    int k1;
    cin >> k1;
    F(i, 0, k1) {
        int x;
        cin >> x;
        players[0].pb(x);
    }

    int k2;
    cin >> k2;
    F(i, 0, k2) {
        int x;
        cin >> x;
        players[1].pb(x);
    }

    F(i, 1, n) {
        dfs(0, i);
        dfs(1, i);
    }

    F(i, 1, n) {
        if (dp[0][i] == 0) {cout << "Loop ";}
        if (dp[0][i] == 1) {cout << "Lose ";}
        if (dp[0][i] == 2) {cout << "Win ";}
    }
    cout << endl;

    F(i, 1, n) {
        if (dp[1][i] == 0) {cout << "Loop ";}
        if (dp[1][i] == 1) {cout << "Lose ";}
        if (dp[1][i] == 2) {cout << "Win ";}
    }
    cout << endl;
    return 0;
}