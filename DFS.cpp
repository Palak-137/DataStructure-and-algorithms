#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
        Graph(int V);
        map<int,bool> visited;
        void addEdge(int v,int w);
        void DFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v){
    visited[v] = true;
    cout<<v<<" ";

    list<int>::iterator  it;
    for(it = adj[v].begin();it!=adj[v].end();++it){
        if(visited[*it]!=true){
            DFS(*it);
        }
    }
}

int main(){
     Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    cout<<"Following is DFS: \n";
    g.DFS(2);
    return 0;
}