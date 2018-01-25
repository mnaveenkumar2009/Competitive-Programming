#include<bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
using namespace std;
vector <int> a;
int main()        
{
        int t;
        cin>>t;int i=0;
        a.pb(1);
        a.pb(2);
        a.pb(4);
        f(i,120)
        {
                int y=a[i+2];
                a.pb(y+3);
        }
        while(t--)
        {
                int n;
                cin>>n;
                f(i,n)
                cout<<a[n-i-1]<<" ";
                cout<<endl;
        }      
}