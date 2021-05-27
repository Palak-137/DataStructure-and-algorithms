#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define INFINITE 100000;
#define m 5

void dijkstra(int G[m][m],int n,int start){
    int cost[m][m], distance[n],pre[m];
    int visited[m],count,mindistance,nextnode;

    for(int i =0;i<m;i++){
        for(int j=0;j<m;j++){
            if(G[i][j] == 0){
                cost[i][j]=INFINITE;
            }else{
                cost[i][j]=G[i][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        distance[i] = cost[start][i];
        pre[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while(count<n-1){
        
        mindistance = INFINITE;
        for(int i=0;i<n;i++){
            if(distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                 if(mindistance + cost[nextnode][i] < distance[i]){
                distance[i] = mindistance + cost[nextnode][i];
                pre[i] = nextnode;
            }
            }
        }
        count++;
    }

int j=n;
for(int i=0;i<n;i++){
    if(i!=start){
        cout<<" \nPath = "<<i;
        j=i;
        do{
            j = pre[j];
            cout<<"<- "<<j;
        }while (j!=start);
        
    }
}
}


int main(){
    //cin>>m;
    int G[m][m];
    cout<<" WRITE THE INPUT FOR GRAPH \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>G[i][j];
        }
    }
    dijkstra(G,m,0);
    return 0;
}