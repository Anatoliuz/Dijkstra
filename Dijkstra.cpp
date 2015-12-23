//
//  Dijkstra.cpp
//  Dijkstra(version 2)
//
//  Created by fix on 13/12/15.
//  Copyright (c) 2015 Anatoly Filinov. All rights reserved.
//

#include "Dijkstra.h"
void Dijkstra( char* argv[])
{
    int vertextNum = 0;
    int s = 0;
    T_vec vec;
    std::ofstream fout(argv[2]);
    vec = ReadData(argv, &vertextNum, &s);

    double d[vertextNum];
    for (int i = 0; i < vertextNum; ++i) {
        d[i] = INF;
    }
    d[s] = 0;
    PriorityQueue queue;
    queue.enqueue(0, s);
    while (!queue.isEmpty()) {
        int v     = queue.top('v');
        int cur_d = queue.top('l');
        queue.dequeue();
        if(cur_d > d[v]) continue;
        for(size_t j = 0; j < vec[v].size(); ++j)
        {
            int len = vec[v][j].first;
            int to  = vec[v][j].second;
            if( d[v] + len < d[to] )
            {
                d[to] = d[v] + len;
                queue.enqueue(d[to], to);
            }
        }
    }
    Printf(vertextNum, s, d, fout);
}