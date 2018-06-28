#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
using namespace std;
int main()
{
    int c,v1,v0,a,l,count=1;
    cin>>c>>v0>>v1>>a>>l;
    c-=v0;
    if(c>0)
    {
        c+=l;
    }
    while(c>0)
    {
        if(v0+a<=v1)
        v0+=a;
        else
        {
            v0=v1;
        }
        c-=v0;
        if(c>0)
        c+=l;
        count++;
        
    }
    cout<<count;
return 0;
}