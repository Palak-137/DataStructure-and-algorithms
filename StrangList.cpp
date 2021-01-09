#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
#define ll unsigned long long int

//logic is equal divison divion of number so better add the number that much time;

int main()
{
    int q;
    cin>>q;
    for(int w=0;w<q;w++)
    {
        ll n,x;
        cin>>n>>x;
        ll p[n],q[n];
        ll sum =0,flag=1;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            sum = sum+p[i];
            q[i] = p[i];
        }

        while(flag==1)
        { 
            for(int i=0;i<n;i++){
                if(p[i]%x==0){
                    sum+= q[i];
                    p[i]/=x;
                }else{
                    flag=0;
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}