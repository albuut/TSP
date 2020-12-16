#ifndef GRAPH_H
#define GRAPH_H
#include "Extra.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>


class Graph {
private:
    int n;
    string fileNames = "names.txt";
    string fileMatrix = "matrix.txt";
    Extra extra;
    
    vector<vector<int>> adjList;
    vector<int*> paths;
    
    string name[4] = {"Riverside", "Perris", "Moreno Valley", "Hemet"};
    int** m;

public:
    //constructor
    Graph();
    //grab data from files
    void getMatrix();
    void printMatrix();
    void printNames();
    //create adjacency list
    void createAdjList();
    void printAdjList();
    void createPath();
    void printPath();
    
    int cost(int*);
};

#endif /* GRAPH_H */

