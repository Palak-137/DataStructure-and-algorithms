#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next=NULL;
        }
};

class Queue{
    Node* front;
    Node* back;

    public:
        Queue(){
            front=NULL;
            back=NULL;
        }

        void push(int x){
            Node *n = new Node(x);

            if(front==NULL){
                back=n;
                front=n;
                return;
            }
            back->next = n;
            back = n;
        }

        void pop(){
            if(front==NULL){
                cout<<"Queue is empty! nothing to pop "<<endl;
                return;
            }
            Node* todelete = front;
            front = front->next;
            delete todelete;
        }
        
        int peek(){
            if(front==NULL){
                cout<<"No element in the queue"<<endl;
                return -1;
            }
            return front->data;
        }

        bool empty(){
            if(front==NULL){
                return false;
            }
            return true;
        }
};

int main(){

    Queue q;
    q.push(3);
    q.push(5);
    q.push(6);
    q.push(8);

    cout<<q.peek()<<endl;
    q.pop();

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