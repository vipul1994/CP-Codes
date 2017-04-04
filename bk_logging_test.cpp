/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pss pair<string,string>
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
#define debug(i, sz, x) F(i,0,sz){cout<<x[i].fi<<","<< x[i].se << " ";}cout<<endl
#define fi first
#define se second
#define INF 1e18

map<string, vector<pss>> logs;

int main() {
//    ifstream fin(("temp/input.txt"));
//    string requestId, timestamp, message;
//    while (fin >> requestId >> timestamp >> message)
//    {
//        cout << requestId << " " << timestamp << " " << message << endl;
//    }

    ifstream inputFile("temp/input.txt");
    string line;

    while (getline(inputFile, line))
    {
        istringstream ss(line);
//        cout << "line = " << line << endl;
        string requestId, timestamp, message;
        int flag = 0;
        int pre_index = 0;
        F(i, 0, line.size()) {
            if (line[i] == ' ') {
                if (flag == 0) {
                    requestId = line.substr(pre_index, i - pre_index);
                    pre_index = i + 1;
                } else {
                    timestamp = line.substr(pre_index, i - pre_index);
                    pre_index = i + 1;
                    break;
                }
                flag = 1;
            }
        }
        message = line.substr(pre_index, line.size() - pre_index);
//        cout << requestId << " " << timestamp << " " << message << endl;
        if (logs.find(requestId) == logs.end()) {
            vector<pss> v;
            v.pb(pss(timestamp, message));
            logs[requestId] = v;
        } else {
            logs[requestId].pb(pss(timestamp, message));
        }


    }

    auto it = logs.begin();
    FI(it, logs) {
        cout << it->first << endl;
        vector<pss> v = it->second;
        debug(i, v.size(), v);
        F(i, 0, v.size()) {
            string ts = v[i].first;
            string message = v[i].se;
            auto found = message.find("processing");
            if (found != string::npos)
                cout << found << endl;
        }
    }

    return 0;
}