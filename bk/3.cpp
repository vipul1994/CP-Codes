/*input
*/

/* Vipul Jain */

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

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

	ofstream outfile ("example.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (outfile.is_open()) {
		outfile << "This is a line.\n";
		outfile << "This is another line.\n";
		outfile.close();
	} else cout << "Unable to open file";

	string line;
	ifstream  infile("example.txt");
	if (infile.is_open()) {
		while ( getline (infile,line) )
		{
		  cout << line << '\n';
		}
		infile.close();
	} else cout << "Unable to open file"; 

    return 0;
}