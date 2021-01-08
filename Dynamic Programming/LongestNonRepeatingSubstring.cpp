#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//sliding window technique
//O(n^2)

int longestSubstring(string s)
{       int n = s.length();

        int ans=0;

        for(int i=0;i<n;i++)
        {
             vector <bool> v(256);

            for(int j=i;j<n;j++){

                if(v[s.at(j)]==true){
                    break;
                }
                else
                {
                    ans = max(ans,j-i+1);
                    v[s.at(j)] = true;
                }
                v[s.at(i)]==false;
            }
        }
        return ans;
}


int main(){
    string s;
    
    cin>>s;
    cout<<longestSubstring(s);
    return 0;
}