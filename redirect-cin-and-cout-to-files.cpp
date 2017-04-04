/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i, a, n) for(int i=(a);i<(n);++i)
#define FB(i, a, n) for(int i=(a);i>=(n);--i)
#define FI(it, x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define Sf(x) scanf("%f",&x)
#define Sd(x) scanf("%lf",&x)
#define M(x, i) memset(x,i,sizeof(x))
#define debug(i, sz, x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fi first
#define se second
#define INF 1e18

int main() {

//    Imp do not delete
//    ifstream inputFile("temp/input.txt");
//    string line;
//
//    while (getline(inputFile, line))
//    {
//        istringstream ss(line);
//
//        string name, reply;
//        int age;
//
//        ss >> name >> age >> reply;
//        cout << name << " " << age << " " << reply << endl;
//    }


    ifstream fin(("temp/input.txt"));
    ofstream outfile ("temp/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    string name, reply;
    int age;

    while (fin >> name >> age >> reply)
    {
        cout << name << " " << age << " " << reply << endl;
        outfile << name << " " << age << " " << reply << endl;
    }

    fin.close();
    outfile.close();



    return 0;
}