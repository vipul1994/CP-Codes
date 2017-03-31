/*input
4 9
6 7 9 12
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

int a[100010];


int main()
{	
    int n, m;
    S(n); S(m);
    F(i, 0, n) {
    	cin >> a[i];
    }
    int counter = 0;
    F(i, 0, n) {
    	F(j, i, n) {
    		int orr = 0;
    		F(k, i, j + 1) {
    			orr |= a[k];
    		}

    		if (orr >= m) {
    			cout << i << " " << j << endl;
    			counter++;
    		}
    	}
    }
    cout << counter << endl;
    return 0;
}