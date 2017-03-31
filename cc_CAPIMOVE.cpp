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
    int t;
    cin >> t;

    F(i, 0, t) {
    	vector<pii> v;
		vector<int> graph[50010];

    	int n;
    	cin >> n;

    	F(i, 0, n) {
    		int a;
    		cin >> a;
    		v.pb(pii(a, i + 1));
    	}

    	sort(v.begin(), v.end(), std::greater<pii>());


    	F(i, 0, n - 1) {
 			int x, y;
 			cin >> x >> y;
 			graph[x].pb(y);
 			graph[y].pb(x);
    	}

    	F(i, 0, n) {
    		graph[i + 1].pb(i + 1);
    	}

    	// F(i, 0, n) {
    	// 	cout << v[i].first << " " << v[i].second << endl;
    	// }


    	int ans[50010];
    	M(ans, 0);

    	int counter = 0;

    	vector<int> bigset;
    	F(i, 0, n) {
    		bigset.pb(i + 1);
    	}

    	F(i, 0, n) {

    		pii a = v[i];
    		int index = a.second;
    		vector<int> nodes = graph[index];

    		// cout << index << endl;
    		// debug(j, nodes.size(), nodes);
    		sort(nodes.begin(), nodes.end());

    		std::vector<int> setinter(50010);
    		std::vector<int> setdiff(50010);

    		vector<int>::iterator it1 = set_intersection(bigset.begin(), 
    			bigset.end(), nodes.begin(), nodes.end(), setinter.begin());
    		setinter.resize(it1-setinter.begin());

    		vector<int>::iterator it2 = set_difference(bigset.begin(), 
    			bigset.end(), nodes.begin(), nodes.end(), setdiff.begin());
    		setdiff.resize(it2-setdiff.begin());

    		// debug(j, setdiff.size(),setdiff);
    		// debug(j, setinter.size(), setinter);


    		int len = setdiff.size();

    		F(j, 0, len) {
    			if (ans[setdiff[j]] == 0) {
    				counter++;
    				ans[setdiff[j]] = index;
    			}
    			if (counter == n) {
    				break;
    			}
    		}
    		if (counter == n) {
    			break;
    		}
    		if (setinter.size() == 0) {
    			break;
    		}

    		bigset = setinter;

    	}

    	F(i, 1, n + 1) {
    		printf("%d ", ans[i]);
    	}
    	cout << endl;
    }
    return 0;
}