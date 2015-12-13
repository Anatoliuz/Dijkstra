//
//  fileWork.h
//  Dijkstra(version 2)
//
//  Created by fix on 13/12/15.
//  Copyright (c) 2015 Anatoly Filinov. All rights reserved.
//

#ifndef __Dijkstra_version_2___fileWork__
#define __Dijkstra_version_2___fileWork__


#include "PriorityQueue.h"


T_vec ReadData( char* argv[], int*, int*);
void Printf(int vertextNum, int s, double* d, std::ofstream &fout);
#endif /* defined(__Dijkstra_version_2___fileWork__) */
