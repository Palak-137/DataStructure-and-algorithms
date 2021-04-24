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

void infixToPostfix(string s){
    int n = s.length();
    stack<char> st;
    string ans="";
    for(int i=0;i<n;i++){
       if((s[i]<='z'&& s[i]>='a') || (s[i]<='Z' && s[i]>='A')){
           ans+=s[i];
       }else
       if(s[i]=='('){
           st.push(s[i]);
       }else
       if(s[i]==')'){
           char t = st.top();
           while(t!='(' && st.empty()==false){
               t=st.top();
               st.pop();
               ans+=t;
              
               if(st.top()=='('){
                   t = st.top();
                   st.pop();
               }
           }
       }else{

           //int pri = priority(s[i]);
           while(st.empty()==false && priority(st.top())>=priority(s[i])){
               char temp = st.top();
               st.pop();
               ans=ans+ temp;     
           }
           st.push(s[i]);
       }
    }
    while(st.empty()==false){
        char temp = st.top();
        ans=ans+temp;
        st.pop();
    }
    cout<<"ans "<<ans<<endl;
}

int main(){
    string s;
    cin>>s;
    infixToPostfix(s);
    return 0;
}