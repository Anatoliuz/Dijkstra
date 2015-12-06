#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <sstream>

#define MAX 10
#define INF 9999999
using namespace std;
template<typename T> void print_queue(T& q)
{
    while (!q.empty()) {
        cout << q.top() << ",";
        q.pop();
    }
    cout << endl;
}
int main(int argc, const char * argv[])
{
    priority_queue<int> m;
    for (int n: {3, 4, -4, -3}) {
        m.push(n);
    }
    print_queue(m);
    ifstream fin("in.txt");
    
    using T_data = pair<int,int>;
    using T_row  = vector<T_data>;
    using T_vec  = vector<T_row>;
    vector < vector < pair <int, int> > > g(3);
    g[0].push_back(make_pair(1,3));
    g[0].push_back(make_pair(3,5));

    cout << "VEC" <<g[0][1].first << endl;
    T_vec vec;
    int s = 1;
    string str;
    while (getline(fin, str)) {
        istringstream iss(str);
        T_row r;
        while (!iss.eof()) {
            T_data d;
            iss >> d.first;
            if(!iss.eof())
                iss >> d.second;
            r.emplace_back(d);
        }
        vec.emplace_back(r);
    }
   
    vector<int> d(6, INF);
    d[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
        if(cur_d > d[v]) continue;
        for(size_t j = 0; j < vec[v].size(); ++j)
        {
            int to  = vec[v][j].first;
            int len = vec[v][j].second;
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                q.push(make_pair(-d[to], to));
            }
        }
    }
    for(int i = 0; i < 6; ++i)
        cout << d[i] << ",";
    cout << endl;
    for(const auto& row: vec){
        for(const auto& data: row)
            cout << "(" << data.first << "," << data.second << ")";
        cout<<endl;
    }
    return 0;
}

