#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool isCyclic(int v,bool visited[],int parent);
    public:
        Graph(int V);
        void addEdge(int v,int w);
        
        bool cycle();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int w,int v){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclic(int v,bool visited[],int parent){
    visited[v] = true;

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            if(isCyclic(*i,visited,v)){
                return true;
            }
        }
    }
    if(*i!=parent){
        return true;
    }
    return false;
}
bool Graph::cycle(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(isCyclic(i,visited,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);

    if(g.cycle()){
        cout<<"Graph contain cycle: ";
    }else{
        cout<<"Graph doesn't contains cycle";
    }

    return 0;
}