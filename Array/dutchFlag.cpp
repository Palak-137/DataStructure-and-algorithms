#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int p[],int n){
    int low = 0,mid = 0, high=n-1;
     while(mid<=high){
         if(p[mid]==0){
             int temp = p[low];
             p[low] = p[mid];
             p[mid]=temp;
             low++;
             mid++;
         }else
         if(p[mid]==1){
             mid++;
         }else
         if(p[mid]==2){
             int temp = p[high];
             p[high] = p[mid];
             p[mid]=temp;
             high--;
         }
     }
     for(int i=0;i<n;i++){
         cout<<p[i]<<" ";
     }
}

int main(){
    int n = 10;
    int p[n] = {0,1,0,2,1,1,0,0,0,2};
    solve(p,n);
    return 0;
}