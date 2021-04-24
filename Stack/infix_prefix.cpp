#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int priority(char c){
    if(c=='^'){
        return 3;
    }else
    if(c=='*'||c=='/'){
        return 2;
    }else
    if(c=='+'||c=='-'){
        return 1;
    }else{
        return -1;
    }
}

void infixPrefix(string s){

}

int main(){
    string s;
    cin>>s;
    infixToPostfix(s);
    return 0;
    return 0;
}