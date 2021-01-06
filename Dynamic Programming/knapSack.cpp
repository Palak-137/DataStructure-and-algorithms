#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int knapsack(int w, int wt[], int val[], int n,int**dp) 
{ 
   if(n<0)
   {
     return 0;    
   }
   if(dp[n][w]!=-1)
   {
      return dp[n][w];    
   }
   if(wt[n]>w)
   {
      dp[n][w] = knapsack(w,wt,val,n-1,dp);
      
      return dp[n][w];
   }else
   {
       dp[n][w] = max(val[n]+knapsack(w-wt[n],wt,val,n-1,dp),knapsack(w,wt,val,n-1,dp));
       return dp[n][w];
   }
}


int knapSack(int w,int wt[],int val[],int n)
{
    int** dp;
    dp = new int*[n];
    
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[w+1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            dp[i][j]=-1;
        }
    }
    return knapsack(w,wt,val,n-1,dp);
}

int main(){
    int n,w;
    cin>>n;
    int wt[n];
    int val[n];
    cin>>w;
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout<<"KnapSack value is : "<<knapSack(w,wt,val,n);

    return 0;
}
