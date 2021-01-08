#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int count(int a){
    return pow(10,a);
}
 
int main()
{
    int q;
    cin>>q;
    for(int w=0;w<q;w++)
    {
        int a;
        cin>>a;
        int i=0;
        cout<<"9";
        if(a==2){
            cout<<"8";
        }else
        if(a>2){
            cout<<"8";
            cout<<"9";
            while(a>3)
            {
              cout<<i%10;
              a--;
              i++;
            }
        }
        cout<<endl;
        
    }
}