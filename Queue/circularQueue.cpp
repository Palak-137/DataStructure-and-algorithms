#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Que{
    int rear,front;
    int size;
    int *arr;
    public:
    Que(int n){
        front = -1;
        rear = -1;
        size = n;
        arr = new int[n];
    }
   
    void enque(int n){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size))){
            cout<<"Queue is full :-( \n";
            return;
        }else
        if(front ==-1){
            front = 0;
            rear = 0;
            arr[rear] = n;
        }else
        if(rear==size-1 && front!=0){
            rear = 0;
            arr[rear] = n;
        }else{
            rear++;
            arr[rear] = n;
        }
    }
    int deque(){
        if(front==-1){
            cout<<"Queue is empty! \n";
            return -1;
        }
        int data = arr[front];
        arr[front]=-1;
        if(front==rear){
            front = -1;
            rear = -1;
        }else{
            front = (front+1)%(size);
        }
        return data;
    }

    void display(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty! \n";
            return;
        }
        cout<<"\n Elements of circular queue\n";
        int i = front;
        while(i!=rear){
            cout<<arr[i]<<" ";
            i = (i+1)%(size);
        }
        cout<<arr[i]<<" ";
        return;
    }
};

int main(){
     Que q(5);
 
    // Inserting elements in Circular Queue
    q.enque(14);
    q.enque(22);
    q.enque(13);
    q.enque(-6);
 
    // Display elements present in Circular Queue
    q.display();
 
    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deque());
    printf("\nDeleted value = %d", q.deque());
 
    q.display();
 
    q.enque(9);
    q.enque(20);
    q.enque(5);
 
    q.display();
 
    q.enque(20);
    return 0;
}