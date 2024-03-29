
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dj[100];
int n;
int rank[100]; 
int findset(int a)
{
    if(dj[a]!=a)
    {
        return dj[a]=findset(dj[a]);
    }
    else
    {
        return a;
    }
}
bool sameset(int a, int b)
{
    return findset(a)==findset(b);
}
void unionset(int a, int b)
{
    int x=findset(a), y=findset(b);
    if(rank[x]>rank[y])
    {
        dj[y]=x;
    }
    else
    {
        dj[x]=y;
        if(rank[x]==rank[y]){
            rank[y]++
            };
    }
}
int main()
{
    int e,u,v,w;
    vector< pair<int, pair<int,int> > > edge; 
    for(int i=0;i<n;i++)
    {
        dj[i]=i;
        rank[i]=0;
    }
    cout<<"Input Number of Edges"<<endl;
    cin>>e;
    cout<<"Input Edges (weight and then two vertices that the edge connects)"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w; 
        edge.push_back({u,{v,w}});
    }
    sort(edge.begin(),edge.end()); 
    int mst=0;
    for(int i=0;i<e;i++)
    {
        int x=edge[i].second.first, y=edge[i].second.second;
        if(!sameset(x,y))
        {
            mst+=edge[i].first;
            unionset(x,y);
        }
    }
    cout<<mst<<endl;
}