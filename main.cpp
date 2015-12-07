#include "PriorityQueue.h"
#define INF 9999999
using namespace std;
int main(int argc, const char * argv[])
{
    if (argc < 3) {
        cout <<"Error:Not enough args" << endl;
        exit(1);
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    if(!fin.is_open()){
        fout<<"Could not open the input file";
        exit(1);
    }
    int vertextNum = 0;
    int s = 0;
    using T_data = pair<int,int>;
    using T_row  = vector<T_data>;
    using T_vec  = vector<T_row>;
    fin >> vertextNum;
    fin.get();
    fin >> s;
    fin.get();
    
    T_vec vec;
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
    double d[vertextNum];
    for (int i = 0; i < vertextNum; ++i) {
        d[i] = INF;
    }
    d[s] = 0;
    PriorityQueue queue;
    queue.enqueue(0, s);
    while (!queue.isEmpty()) {
        int v = queue.top('p');
        int cur_d = -queue.top('v');
        queue.dequeue();
        if(cur_d > d[v]) continue;
        for(size_t j = 0; j < vec[v].size(); ++j)
        {
            int to  = vec[v][j].first;
            int len = vec[v][j].second;
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                queue.enqueue(-d[to], to);
            }
        }
    }
    fout << "Trip length from " << s <<" to vertex:"<<endl;
    for(int i = 0; i < vertextNum; ++i)
    {
        if (i!=s) {
            fout << i << " is " << d[i] << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}

