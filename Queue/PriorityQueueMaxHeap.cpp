#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int p[100];
int N;

void adjustElement(int i,int n){
    if(2*i<=n){
        int temp = 0;
        if(p[2*i]>p[i]){
            temp = 2*i;
        }
        if(2*i+1<n+1 && p[2*i+1]>p[i]){
            if(temp!=0){
                if(p[temp]<p[2*i+1]){
                    temp = 2*i+1;
                }
            }temp = 2*i+1;
        }
        if(temp!=0){
            swap(p[i],p[temp]);
            adjustElement(temp,n);
        }
    }
    
}

void heapify(int n){
    for(int i=n/2;i>0;i--){
        adjustElement(i, n);
    }
}

void display(){
    cout<<"Current elements are: ";
    for(int i=1;i<=N;i++){
        cout<<p[i]<<" ";
    }cout<<endl<<endl;
}

void insert(){
    int c ;
	if(N==100){
		cout <<"Array is full , can't insert more \n" ; return;
	}
	cout << "Enter the priority : " ; cin >> c ;
	N++ ;
	p[N] = c ;
	heapify(N) ;
	display() ;
}

void delet (){
	if(N==0){
		cout <<"Empty queue Deletion not possible \n" ; return;
	}
	cout <<"Max : "<< p[1]<<endl;
	p[1] = -1 ;
	heapify(N) ;
	N-- ;
	p[N] = max(p[N],p[N+1]) ;
	display() ;
}



int main(){
    // Making max heap

    /*
          45
        /    \
       31     14
     /   \    / \
    13   20  7   11
   /  \
  12    20

    queue:-
    45 31 14 13 20 7 11 12 20

    */
int n ;
	cout << "Enter the no. of elements :  " ;
	cin >> n ;
	N = n ;
	p[0] = -1 ;
	cout <<"Enter the priorities : " ;
	for(int i=1 ;i<N+1 ; i++){
		cin >> p[i] ;
	}
	heapify(N) ;
    display();
}