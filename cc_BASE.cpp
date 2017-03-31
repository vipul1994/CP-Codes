/*input
4
6
9
11
24
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

ill fast_pow(ill value,ill power)
{
    ill result = 1;
    while(power > 0)
    {
        if(power & 1) {
        	result = result * value;
		}
        value = value * value;
        power /= 2;
    }
    return result;
}

int intlog(double base, double x) {
    ill result = 0;
    ill power = 1;
    while (power <= x) {
    	result++;
    	power *= base;
    }
    return result - 1;
}

ill power_array[1000010][41];

ill custom_power(ill base, ill x) {
    int i = 0;
    int j = 40;
    while (i < j) {
    	int mid = (i + j) / 2;
    	if (power_array[base][mid] <= x) {
    		i = mid;
    	} else {
    		j = mid;
    	}
    }
    return power_array[base][i];
}

void precompute() {
	F(i, 2, 1000010) {
		power_array[i][0] = 1;
		ill power = 1;
		int index = 1;
		while (power <= 1000000000010) {
			power *= (ill)i;
			power_array[i][index++] = power;
		}
	}
}

int main()
{	
	// F(i, 2, 1000010) {
	// 	F(j, 0, 41) {
	// 		power_array[i][j] = 1000000000010;
	// 	}
	// }
	precompute();
	// cout << power_array[1000000][3] << endl;
    int t;
    S(t);
    F(i, 0, t) {
    	ill n;
    	Sl(n);
    	if (n == 1) {
    		cout << "INFINITY" << endl;
    		continue;
    	}
    	// cout << "N = " << n << endl;
    	ill counter = n - (n / 2);
    	ill ends = sqrt((double)n);
    	F(i, 2, ends + 1) {
    		ill max_power = custom_power(i, n);
    		// cout << i << " " <<  max_power << endl;
    		if (n - max_power <= max_power - 1) {
    			counter++;
    		}
    		// cout << i << endl;
    	}
    	// cout << endl;
    	// cout << "ans = " << counter << endl;
    	cout << counter << endl;
    }
    return 0;
}	