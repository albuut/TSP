/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Albuu
 *
 * Created on December 16, 2020, 11:49 AM
 */

#include <cstdlib>

#include "Graph.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Graph graph;
    cout << "Traveling Salesman Problem" << endl << endl;;
    cout << "Adjacency matrix" << endl;
    graph.printMatrix();
    cout << "\nAdjacency List" << endl;
    graph.printAdjList();
    cout << "\nPaths/Cost" << endl;
    graph.printPath();
    cout << "\nCheapest Path" << endl;
    graph.printLowest();
    cout << "\nShortest Path" << endl;
    cout << "Path's 1-6 are the shortest path. You have to travel through 4 vertices to visit each location and come back." << endl;
    return 0;
}

