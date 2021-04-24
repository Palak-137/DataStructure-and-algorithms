#include <bits/stdc++.h>
using namespace std;

class Queue{
    stack<int> s1;
    public:
        void push(int x){
            s1.push(x);
        }
        int pop(){
            if(s1.empty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            int x = s1.top();
            s1.pop();
            if(s1.empty()){
                return x;
            }
            int item = pop();
            s1.push(x);
            return item;
        }
        int seek(){
            if(s1.empty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return s1.top();
        }

        bool empty(){
            if(s1.empty()){
                return true;
            }
            return false;
        }

};

int main(){
    return 0;
}