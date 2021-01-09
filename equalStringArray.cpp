#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
#define ll unsigned long long int

 bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size();
        int m = word2.size();
        string w1="",w2="";
        for(int i=0;i<n;i++){
            w1+=word1[i];
        }
        for(int i=0;i<m;i++){
            w2+=word2[i];
        }
        return (w1==w2);
    }


int main(){
    int n,m;
    cin>>n>>m;
    vector<string> p(n);
    vector<string> q(m);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        cin>>q[i];
    }
    if( arrayStringsAreEqual(p,q)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}