#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// snake ladder problem
// directed , unweighted 
// if unweighted apply BFS for shotest path

struct Node{
    int ver;
    int min_dist;
};


class Graph{
    int V;
    vector<int> *adj;
    public:
        Graph(int V);
        void addEdge(int v,int w);
        bool BFS(int s,int des,int pred[],int dest[]);
        void printPath(int s,int dest);
};


Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

bool Graph::BFS(int s,int des,int pred[],int dest[]){
    bool *visited = new bool[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
        pred[i] = -1;
        dest[i] = INT_MAX;
    }
    queue<int> q;
    q.push(s);
    dest[s]=0;
    visited[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]] == false){
                visited[adj[u][i]] = true;
                dest[adj[u][i]] = dest[u] + 1;
                pred[adj[u][i]] = u;
                q.push(adj[u][i]);

                if(adj[u][i]==des){
                    return true;
                }
            }
        }
    }
    return false;
}

void Graph::printPath(int s,int  dest){
    int pred[V],dis[V];

    if(BFS(s,dest,pred,dis)==false){
        cout<<"Graph has cycle\n";
        return;
    }

    vector<int> path;
    int cr = dest;
    path.push_back(cr);

    while(pred[cr]!=-1){
        path.push_back(pred[cr]);
        cr = pred[cr];
    }

    cout << "Shortest path length is : "<< dis[dest];

    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main(){

    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    Graph g(50);

    //insert edges

    for(int u=0;u<36;u++){
        for(int dice = 1;dice<=6;dice++){
            int t = u + dice + board[u+dice];
            g.addEdge(u,t);
        }
    }
    g.printPath(0,36);
    return 0;
}