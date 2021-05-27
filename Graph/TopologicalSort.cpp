// graph must be directed acyclic graph
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    list<int> *adj;
    public: 
        Graph(int n);
        void addEdge(int v,int w);
        void topologicalSort();
};
Graph::Graph(int n){
    this->n = n;
    adj = new list<int>[n];
}
void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void  Graph::topologicalSort(){
    vector<int> degree(n,0);

    for(int i=0;i<n;i++){
        list<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            degree[*it]++;
        }
    }
    queue<int> qu;
    for(int i=0;i<n;i++){
        if(degree[i]==0){
            qu.push(i);
        }
    }
    vector<int> ans;
    while(!qu.empty()){
        int t = qu.front();
        ans.push_back(t);
        qu.pop();

        list<int>::iterator i;
        for(i = adj[t].begin();i!=adj[t].end();i++){
            int m = --degree[*i];
            if(m==0){
                qu.push(*i);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return;
}

int main(){

    int n;
    cout<<"Enter the number of node in graph: ";
    cin>>n;
    Graph g(n);
    for(int i=0;i<n;i++){
        int t,p;
        cin>>t>>p;
        g.addEdge(t,p);
    }
    g.topologicalSort();
    
    return 0;
}