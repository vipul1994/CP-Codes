/*input
6 1
5 1 2 3 4 1
*/
/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<double,double>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FB(i,a,n) for(int i=(a);i>=(n);--i)
#define FI(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define Sf(x) scanf("%f",&x)
#define Sd(x) scanf("%lf",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fi first
#define se second

ill dp[100010];
ill arr[100010];

int main()
{	
	M(dp, 0);
    int n;
    ill x;
    S(n); Sl(x);
    F(i, 0, n) {
    	Sl(arr[i]);
    	dp[arr[i]]++;
    }
    ill ans = 0;
    F(i, 0, n) {
    	ill y = arr[i] ^ x;
    	dp[arr[i]] -= 1;
    	if (y > 100000) {
    		continue;
    	}
    	ans += dp[y];
    }
    cout << ans << endl;
    return 0;

}