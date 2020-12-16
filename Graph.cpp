#include "Graph.h"

Graph::Graph(){
    getMatrix();
    createAdjList();
    createPath();
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
void Graph::createPath(){
    int* path = new int[n-1];
    for(int i = 0; i < n-1; i++){
        path[i] = i+1;
    }
    do{
        int* perm = new int[n-1];
        for(int i = 0; i < n-1; i++){
            perm[i] = path[i];
        }
        paths.push_back(perm);
    }while(next_permutation(path,path+3));
}
void Graph::printPath(){
    for(int i = 0; i < paths.size(); i++){
        cout << name[0];
        for(int j = 0; j < n-1; j++){
            cout << " -> " << name[paths[i][j]];
        }
        cout << " -> " <<  name[0] << ": " << cost(paths[i]) << endl;
    }
}
int Graph::cost(int* path){
    int sum = 0;
    //Riverside
    int location = 0;
    for(int i = 0; i < n-1; i++){
        sum += m[location][path[i]];
        //Set start location to where we moved to
        location = path[i];
    }
    //Return to Riverside
    sum += m[location][0];
    return sum;
}