#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int lis(int a[],int n){
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && lis[i]<lis[j]+1){
                lis[i] = lis[j]+1;
            }
        }
    }
    return *max_element(lis,lis+n);

}

int main(){
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"Length of longest increasing substring "<<lis(p,n);
    return 0;
}