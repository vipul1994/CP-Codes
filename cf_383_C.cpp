/*input
10
8 10 4 3 2 1 9 6 5 7
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

int a[110];
bool visited[110];

int dfs(int source, int node)
{
	if (visited[node] && node != source) {
		return -1;
	}
	if (visited[node] && node == source) {
		return 0;
	}
	visited[node] = true;
	int depth = dfs(source, a[node] - 1);
	if (depth == -1) {return -1;}
	return depth + 1;
}

int gcd(int a , int b)
{
   if(b == 0) return a;
   return gcd(b, a % b);
}

int lcm(int a, int b) {
	return ((a * b) / gcd(a, b));
}

int main()
{	
	M(visited, 0);
	int n;
    S(n);
    F(i, 0, n) {
    	S(a[i]);
    }
    int check = 0;
    int ans = -1;
    F(i, 0, n) {
    	if (!visited[i]) {
    		check = dfs(i, i);
    		if (check == -1) {
    			break;
    		}
    		// cout << check << endl;
    		if (check % 2 == 0) {
      			check /= 2;
    		}
    		if (ans == -1) {
    			ans = check;
    		}
    		ans = lcm(ans, check);
    	}
    }
    if (check == -1) {
    	cout << -1 << endl;
    } else {
		cout << ans << endl;
	}
    return 0;
}