#include <bits/stdc++.h>
#define int long long
#define br cout<<"\n"
#define pb push_back
#define vi vector<int>
#define vf vector<float>
#define vc vector<char>
#define vs vector<string>
#define vp vector<pair<int,int>>
#define dd double
#define sa(a,n) sort(a,a+n)
#define sar(a,n) sort(a,a+n,greater<int>())
#define sv(v) sort(v.begin(),v.end())
#define svr(v) sort(v.begin(),v.end(),greater<int>())
#define pt(x) cout<<(x)<<"\n"
#define psa(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n"
#define psv(v) for(int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<"\n"
#define vpt(v) for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<"\n"
#define apsc ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define loop0(n) for(int i=0;i<n;i++)
#define loop1(n) for(int i=1;i<=n;i++)
#define rev(a,n) for(int i=n-1;i>=a;i--)
//#define all(x) x.begin(),x.end()
const int M = 1e9 + 7;
const double pi= 3.14159265358979323846;
 
//cout<<"sum="<<sum<<"\n";
//AND THE SHOW BEGINS :)//
using namespace std;
vector<int>adj[100005];
int vis[3]={0};
signed main()
{
    apsc;
    int t=1;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int arr[n];
        int sum=0;
        loop0(n)
        {
            cin>>arr[i];
            if(arr[i]%k!=0) sum+=arr[i];
        }
        int s1=0,s2=0;
        //max
        loop0(n)
        {
            int x=arr[i]/k;
            if(arr[i]%k!=0) x++;
            s1+=x;
        }
        loop0(n)
        {
            int x=arr[i]/k;
            if(arr[i]%k==0) s2+=x;
 
        }
        s2+=(sum/k);
        if(sum%k!=0) s2++;
        cout<<s2<<" "<<s1<<"\n";
    }
    return 0;
}