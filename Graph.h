#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Graph {
private:
    int n;
    string fileNames = "names.txt";
    string fileMatrix = "matrix.txt";
    
    vector<vector<int>> adjList;
    vector<int*> paths;
    vector<int> cost;
    
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
    void printLowest();
    
    int getCost(int*);
};

#endif /* GRAPH_H */

