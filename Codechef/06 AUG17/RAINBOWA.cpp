#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
using namespace std;
 
int main()
{
    int t;
    sd(t);
    while(t--)
    {
       int n,i;bool we=1;
       sd(n);
       vector <int> a(n);
       f(i,n)
       {
           sd(a[i]);
       }
       if(a[0]!=1)we=0;
       int c=1;
       if(n%2){
       f(i,(n/2)+1)
       {
           if(a[i]!=a[n-i-1])
           {
               we=0;
               break;
           }
           else
           {
               if(a[i]!=c)
               {
                   if(a[i]==c+1)
                   {
                       c++;
                   }
                   else
                   {
                       we=0; break;
                   }
               }
               
           }
       }
       }
       else
       {
           
       f(i,(n/2))
       {
           if(a[i]!=a[n-i-1])
           {
               we=0;
               break;
           }
           else
           {
               if(a[i]!=c)
               {
                   if(a[i]==c+1)
                   {
                       c++;
                   }
                   else
                   {
                       we=0; break;
                   }
               }
               
           }
       }
       }
        
           if(c!=7)we=0;
       
       if(we)
       {
           printf("yes\n");
       }
        else
        {
            printf("no\n");
        }
    }
 
    return 0;
}