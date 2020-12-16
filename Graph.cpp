/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: Albuu
 * 
 * Created on December 16, 2020, 12:15 PM
 */

#include "Graph.h"

Graph::Graph(){
    getMatrix();
    createAdjList();
}
void Graph::getMatrix(){
    fstream fin;
    fin.open(fileMatrix);
    if(fin){
        string SIZE;
        string line;
        int indx = 0;
        
        getline(fin,SIZE);
        n = stoi(SIZE);
        string* data = new string[n];
        
        while(getline(fin,line)){
            stringstream s(line);
            m[indx] = new int[n];
            for(int i = 0; i < n; i++){;
                getline(s,data[i],'\t');
                m[indx][i] = stoi(data[i]);             
            }
            indx++;
        }
        
        delete[] data;
    }else{
        cout << "Error in opening file " << fileMatrix << endl;
    }
    fin.close();
}
void Graph::printMatrix(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
void Graph::createAdjList(){
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j < n; j++){
            if(m[i][j] > 0){
                row.push_back(j);
            }
        }
        adjList.push_back(row);
    }
}
void Graph::printAdjList(){
    for(int i = 0; i < n; i++){
        cout << name[i];
        for(int j = 0; j < adjList[i].size(); j++){
            cout << " -> " << name[adjList[i][j]];
        }
        cout << endl;
    }
}