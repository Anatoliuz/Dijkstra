//
//  fileWork.cpp
//  Dijkstra(version 2)
//
//  Created by fix on 13/12/15.
//  Copyright (c) 2015 Anatoly Filinov. All rights reserved.
//
#include "fileWork.h"
void Printf(int vertextNum, int s, double* d, std::ofstream &fout){
    fout << "Trip length from " << s <<" to vertex:"<<std::endl;
    for(int i = 0; i < vertextNum; ++i)
    {
        if (i!=s) {
            fout << i << " is " << d[i] << std::endl;
        }
    }
}

T_vec ReadData( char** argv, int* vertextNum, int* startPoint)
{
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    if(!fin.is_open()){
        fout<<"Could not open the input file";
        fout.close()    ;
        exit(1);
    }


    fin >> *vertextNum;
    fin.get();
    fin >> *startPoint;
    fin.get();
    
    T_vec vec;
    std::string str;
    while (getline(fin, str)) {
        std::istringstream iss(str);
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
    return vec;
}