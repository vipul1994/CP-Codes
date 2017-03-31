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

struct Person {
	string name;
	int age;
	string gender;

	Person(string name, int age, string gender) {
		this->name = name;
		this->age = age;
		this->gender = gender;
	}

	// equality comparison. doesn't modify object. therefore const.
    bool operator<(const Person& a) const
    {
        return (this->age < a.age);
    }
};

int main()
{	
    int n;
    cin >> n;

    std::vector<Person> v;
    F(i, 0, n) {
    	string name, gender; 
    	int age;

    	cin >> name >> age >> gender;
    	v.pb(Person(name, age, gender));
    }

    sort(v.begin(), v.end());

    F(i, 0, n) {
    	cout << v[i].name << " " << v[i].age << " " << v[i].gender << endl;
    }
    return 0;
}