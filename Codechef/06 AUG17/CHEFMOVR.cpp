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
        long long n,d,i=0,j=0;bool we=1;
        long long count=0;
        slld(n);
        slld(d);
        vector <long long> a(n),sum(d,0) , avg(d,-1);
        vector < vector <long long> > b( d , vector <long long> (0,0));
        f(i,n)
        {
            slld(a[i]);
            b[i%d].pb(a[i]);
        }
        f(i,d)
        {
 
            f(j,b[i].size())
            {
                sum[i]+=b[i][j];
 
            }
        }
 
        f(i,d)
        {
            if(sum[i]%(b[i].size())==0)
          avg[i]=sum[i]/(b[i].size());
          else
            we=0;
        }
        f(i,d-1)
        {
 
            if(avg[i]!=avg[i+1])we=0;
        }
        if(we){
         f(i,d)
        {
            f(j,b[i].size()-1)
            {
                long long jj= abs(avg[i]-b[i][j]);
               if(avg[i]>b[i][j])
               {
                   b[i][j+1]-=jj;
                   count+=jj;
 
               }
               else
               {
                   b[i][j+1]+=jj;
                   count+=jj;
 
               }
            }
        }
 
        printf("%lld\n",count);
        }
        else
        {
            printf("-1\n");
        }
 
    }
 
    return 0;
}