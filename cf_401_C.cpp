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
    int n, m;
    S(n); S(m);
    int a[n][m];
    int b[n][m];
    F(i, 0, n) {
    	F(j, 0, m) {
    		cin >> a[i][j];
    	}
    } 
    F(j, 0, m) {
    	b[0][j] = 1;
    }
    F(i, 1, n) {
    	F(j, 0, m) {
    		if (a[i - 1][j] <= a[i][j]) {
    			b[i][j] = b[i - 1][j] + 1;
    		} else {
    			b[i][j] = 1;
    		}
    	}
    }

    int c[n];
    M(c, 0);
    F(j, 0, m) {
    	F(i, 0, n) {
    		c[i] = max(c[i], b[i][j]);
    	}
    }

    int k;
    cin >> k;

    F(i, 0, k) {
    	int l, r;
    	cin >> l >> r;

    	if (c[r - 1] >= r - l + 1) {
    		cout << "Yes" << endl;
    	} else {
    		cout << "No" << endl;
    	}
    }
    return 0;
}