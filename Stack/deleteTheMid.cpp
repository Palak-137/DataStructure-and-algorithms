#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DDL{
    public:
    DDL* prev;
    int data;
    DDL* next;
};

class stackDDl{
    public:
    DDL* head;
    DDL* mid;
    int count;
};
stackDDl* createStack(){
    stackDDl* ss = new stackDDl();
    ss->count = 0;
    return ss;
}

void push(stackDDl* ss,int n){
    DDL* ll = new DDL();
    ll->data = n;
    ll->prev = NULL;
    ll->next = ss->head;
    ss->count+=1;

    if(ss->count == 1){
        ss->mid = ll;
    }else{
        ss->head->prev = ll;
        if(!(ss->count & 1)){
            ss->mid = ss->mid->prev;
        }
    }
    ss->head = ll;
}

int  pop(stackDDl* ss){
    if(ss->count==0){
        cout<<"Stack is empty\n";
        return-1;
    }
    DDL* head = ss->head;
    int item = head->data;
    ss->head = head->next;

    if(ss->head!=NULL){
        ss->head->prev = NULL;
    }
    ss->count-=1;

    if(!(ss->count & 1)){
        ss->mid = ss->mid->next;
    }

    free(head);

    return item;
}

int findMiddle(stackDDl* ss){
    if (ss->count == 0) {
        cout << "Stack is empty now\n";
        return -1;
    }
 
    return ss->mid->data;
   
}

int  deletemiddle(stackDDl* ss){  
           int temp=ss->mid->data;
        ss->mid->prev->next = ss->mid->next;
        ss->mid->next->prev = ss->mid->prev->next;
         
        delete ss->mid;
        return temp;
     }


int main(){

    stackDDl* ms = new stackDDl();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);


    return 0;
}
