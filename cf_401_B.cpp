/*input
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

int main()
{	
    int n;
    S(n);
    string a, b;
    cin >> a >> b;

    int ans1, ans2;

    // sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;

    while (i < n && j < n) {
    	if (b[j] < a[i]) {
    		++j;
    	} else {
    		++j;
    		++i;
    	}
    }

    ans1 = n - i;


    i = 0;
    j = 0;
    while (i < n && j < n) {

    	if (b[j] > a[i]) {
    		++j;
    		++i;
    	} else {
    		++j;
    	}
    }

    ans2 = i;

    cout << ans1 << endl;

    cout << ans2 << endl;
    return 0;
}