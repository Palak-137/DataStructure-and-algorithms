#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int R,C;

void printmatrix(char p[][20]){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<p[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void floodfill(char p[][20],int i,int j,char color,char ch){
    if(i<0 || j<0 || i>=R || j>=C || p[i][j]!=ch){
        return;
    }
    p[i][j] = color;
    floodfill(p,i,j+1,color,ch);
    floodfill(p,i+1,j,color,ch);
    floodfill(p,i,j-1,color,ch);
    floodfill(p,i-1,j,color,ch);

}

int main(){
    char p[20][20];
    
     for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            p[i][j]='.';
        }
    }

    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>p[i][j];
        }
    }
    cout<<endl;
     printmatrix(p);
     floodfill(p,6,6,'R','.');
     printmatrix(p);
    return 0;
}