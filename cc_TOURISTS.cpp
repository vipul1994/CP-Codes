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

#define ll long long

const int MAXN = 200005;
const int MOD = 1000000007;

int cnt[MAXN],vis[MAXN],U[MAXN],V[MAXN],temp[MAXN];
vector<pair<int,int>> g[MAXN];

void dfs(int a){
	temp[a] = 1;
	while(cnt[a] < g[a].size()){	
		int j = g[a][cnt[a]].first;
		int k = g[a][cnt[a]].second;
		if(!vis[k]){
			U[k] = a; V[k] = j;
			cnt[a]++;
			vis[k] = 1;
			dfs(j);
		}
		else cnt[a]++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,m; cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		g[a].push_back({b,i});
		g[b].push_back({a,i});
		cnt[a]++; cnt[b]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i] & 1){
			cout << "NO" << '\n';
			return 0;
		}
	}
	memset(cnt,0,sizeof cnt);
	dfs(1);
	for(int i=0;i<m;i++){
		if(!vis[i]){
			cout << "NO" << '\n';
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!temp[i]) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	for(int i=0;i<m;i++) cout << U[i] << ' ' << V[i] << '\n';
	return 0;
}