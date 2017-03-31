/*input
1
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

ill a[100010];
bool bit_set[100010][31];

void set_bit(int index) 
{
	ill num = a[index];
	ill b = 1;
	int i = 0;
	while (b <= num) {
		if (b & num) {
			bit_set[index][i] = 1;	
		} else {
			bit_set[index][i] = 0;	
		}
		i++;
		b <<= 1;
	}
}

int main()
{	
    int t;
    cin >> t;
    while (t--) {
    	ill n, k;
    	cin >> n >> k;
    	F(i, 0, n) {
    		cin >> a[i];
    		set_bit(i);
    	}
    	int left = 0;
    	ill orr = 0;
    	ill counter = 0;
    	int orr_bit_set[31];
    	F(i, 0, 31) {
    		orr_bit_set[i] = 100010;
    	}
    	F(i, 0, n) {
    		orr |= a[i];
    		F(j, 0, 31) {
    			if (bit_set[i][j] == 1)
    				orr_bit_set[j] = i;
    		}
    		// cout << "orr " << orr << endl;
    		if (orr >= k) {
	    			cout << i << endl; 
	    			int index = 100010;
	    			F(j, 0, 31) {
	    				index = min(index, orr_bit_set[j]);
	    			}
	    			// cout << "index = " << index << endl;
	    			// cout << "left = " << left << endl;
	    			// cout << "counter_lat = " << (index - left + 1) * (n - 1 - i + 1) << endl;
					counter += ((index - left + 1) * (n - 1 - i + 1));
					// cout << "counter " << counter << endl;
					F(j, 0, 31) {
						if (orr_bit_set[j] == index) {
							orr_bit_set[j] = 100010;
						}
					}
					orr ^= a[index];
					left = index + 1;
    		}
    	}
    	cout << counter << endl;
    }
    return 0;
}