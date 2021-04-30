#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
Tabulation method to store the value and make dp faster
    steps for tabulation-:
    1. storage
    2. meaning - what you will store
    3. direction to traverse
    4. solve
*/

int path[1000000];

int countPath(int n,int path[]){
    if(n==0){
        return 1;
    }else
    if(n<0){
        return 0;
    }
    else
    if(path[n]>0){
        return path[n];
    }
        int p1 = countPath(n-1,path);
        int p2 = countPath(n-2,path);
        int p3 = countPath(n-3,path);

        path[n] = p1+p2+p3;

        return p1+p2+p3;
    
}

int main(){
    int n;
    cin>>n;
    memset(path,0,sizeof(path));
    cout<<countPath(n,path)<<endl;
    return 0;
}