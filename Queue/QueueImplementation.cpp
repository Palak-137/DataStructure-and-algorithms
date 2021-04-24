#include <bits/stdc++.h>
using namespace std;
#define n 50

class Queue{
    int *arr;
    int front;
    int back;
    public:
        Queue(){
            arr = new int[n];
            front=-1;
            back=-1;
        }

        void push(int x){
            if(back==n-1){
                cout<<"Queue is overflowed! "<<endl;
                return;
            }
            back++;
            arr[back]=x;

            if(front==-1){
                front++;
            }
            return;
        }

        void pop(){
            if(front==-1 && front>back){
                cout<<"No element in queue";
                return;
            }
            front++;
            return;
        }
        int peek(){
            if(front==-1 && front>back){
                cout<<"No element in queue";
                return -1;
            }
            return arr[front];
        }

        bool empty(){
             if(front==-1 && front>back){
               return true;
            }else{
                return false;
            }
        }
};

int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.peek()<<endl;
    q.pop();


   return 0;
}