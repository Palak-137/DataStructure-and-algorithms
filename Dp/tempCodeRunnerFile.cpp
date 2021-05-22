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
     