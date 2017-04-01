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
    string s;
    cin >> s;

    // stack<char> S;

    // F(i, 0, s.size()) {
    // 	if (s[i] == '(') {
    // 		S.push('(');
    // 	} else if (s[i] == ')') {
    // 		S.pop();
    // 	}
    // }

    // if (S.size() != 0) {
    // 	cout << "No" << endl;
    // } else {
    // 	cout << "Yes" << endl;
    // }

    int counter = 0;
    F(i, 0, s.size()) {
    	if (s[i] == '(') {
    		counter++;
    	} else if (s[i] == ')') {
    		counter--;
    	}
    }

    if (counter != 0) {
    	cout << "No" << endl;
    } else {
    	cout << "Yes" << endl;
    }
    
    return 0;
}