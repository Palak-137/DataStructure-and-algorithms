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

int path(int n,int p[]){
     int dp[n+1];
     dp[n]=1;
     
     for(int i=n-1;i>=0;i--){
         for(int j=1;j<=p[i] && i+j<n+1;j++){
             dp[i]+=dp[i+j];
         }
     }
     return dp[0];
}

int main(){
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<path(n,p)<<endl;
    
    return 0;
}