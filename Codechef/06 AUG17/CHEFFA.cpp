#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
 
using namespace std;
 
int f2(vector <int> a,int pos)
{
    int i;int count=1;
 
 
    if(pos==a.size()-1)return 0;
    
    if(pos==a.size()-2){
        int y=min(a[pos],a[pos+1]);
        vector <int> c = a;
        //count+=(f2(c,pos+1)-1);
        f(i,y)
        {
            vector <int> b= a;
        b[pos]-=i+1;
        b[pos+1]-=i+1;
        b.pb(i+1);
        //if(i==0)count--;
        count+=f2(b,pos+1);
        }
    
        
    }
    else
    {
        int y=min(a[pos],a[pos+1]);
        vector <int> c = a;
        count+=(f2(c,pos+1)-1);
    f(i,y)
    {   vector <int> b= a;
        b[pos]-=i+1;
        b[pos+1]-=i+1;
        b[pos+2]+=i+1;
        //if(i==0)count--;
        count+=f2(b,pos+1);
    }
    
    }
    
    return (count);
}
int main()
{
    int t;
    sd(t);
    while(t--)
    {   int n,i;
        cin>>n;
        vector <int> a(n);
        f(i,n)cin>>a[i];
        if(n!=1)
        cout<<f2(a,0)<<endl;
        else
        cout<<"1\n";
    }
 
    return 0;
}