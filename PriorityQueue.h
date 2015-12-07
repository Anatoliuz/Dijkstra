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
class PriorityQueue {
    static const int MAX_SIZE = 1000;
    int size;
    struct Elem {
        double val;
        double vertex;
        Elem(int v = 0, int p = 0) {
            val = v;
            vertex = p;
        }
    } a[MAX_SIZE];
    void up(int i) ;
    void down(int i);
public:
    PriorityQueue() ;
    void enqueue(double value, double priority);
    void dequeue() ;
    int top(char c);
    bool isEmpty();
};
#endif