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

string a[1010];


int main()
{	
    int t;
    S(t);
    while (t--) {
    	int n, m;
    	S(n); S(m);

    	F(i, 0, n) {
    		cin >> a[i];
    	}

    	int flag = 0;

    	F(i, 0, n) {
    		F(j, 0 , m) {
    			if (i < n - 1 && a[i][j] == 'B') {
    				if (a[i + 1][j] == 'A' || a[i + 1][j] == 'W') {
    					cout << "no" << endl;
    					flag = 1;
    					break;
    				}
    			}

    			if (j == 0 || j == m - 1) {
    				if (a[i][j] == 'W') {
    					cout << "no" << endl;
    					flag = 1;
    					break;
    				}
    			}

    			if (i == n - 1 && a[i][j] == 'W') {
    				if (a[i][j - 1] == 'A' || a[i][j + 1] == 'A') {
    					cout << "no" << endl;
    					flag = 1;
    					break;
    				}
    			}

    			if (i < n - 1 && a[i][j] == 'W') {
    				if (a[i][j - 1] == 'A' || a[i][j + 1] == 'A' || a[i + 1][j] == 'A') {
    					cout << "no" << endl;
    					flag = 1;
    					break;
    				}
    			} 
    		}
    		if (flag) {
    			break;
    		}
    	}
    	if (!flag) {
    		cout << "yes" << endl; 
    	}
    }
    return 0;
}