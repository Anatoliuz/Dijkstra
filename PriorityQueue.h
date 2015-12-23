//
//  PriorityQueue.h
//  Dijkstra(version 2)
//
//  Created by fix on 06/12/15.
//  Copyright (c) 2015 Anatoly Filinov. All rights reserved.
//

#ifndef __Dijkstra_version_2___PriorityQueue__
#define __Dijkstra_version_2___PriorityQueue__

#include <iostream>
#include <cassert>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <sstream>

#define INF 9999999

using T_data = std::pair<int,int>;
using T_row  = std::vector<T_data>;
using T_vec  = std::vector<T_row>;


class PriorityQueue {
    static const int MAX_SIZE = 1000;
    int size;
    struct Elem {
        double length;
        double vertex;
        Elem(int v = 0, int p = 0) {
            length = v;
            vertex = p;
        }
    } a[MAX_SIZE];
    void up(int i) ;
    void down(int i);
public:
    PriorityQueue() ;
    void enqueue(double length, double vertex);
    void dequeue() ;
    int top(char c);
    bool isEmpty();
};
#endif