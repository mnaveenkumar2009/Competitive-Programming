    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    int main() {
        #define N 100004
     
        int i;
        
    int q,t;
    scanf("%d",&t);
    vector <vector <int> > divisors(N, vector <int> (0,0) );
    f(i,N)
    {
       if(i!=0)
       {
           for (int j=1; j<=sqrt(i); j++)
        {
            if (i%j==0)
            {
                if (i/j == j)
                    divisors[i].pb(j);
     
                else 
                {
                    divisors[i].pb(j);
                    divisors[i].pb(i/j);
                }
            }
        }
       }
    }
     
    while(t--)
    {   
        long long n,q,j;
        slld(n);slld(q);
        long long a[n];
        vector <long long > ans(n,0);
        
        f(i,n)
        {
           slld(a[i]);
           a[i]*=a[i];
           a[i]=a[i]%mod;
           f(j,divisors[i+1].size())
           {
               ans[divisors[i+1][j]-1]=(ans[divisors[i+1][j]-1]+a[i])%mod;
               
           }
        }
        while(q--)
        {
            int h;
            sd(h);
            long long x,y;
            if(h==1)
            {
                slld(x);
                printf("%lld\n",ans[x-1]);
            }
            else
            {
                slld(x);slld(y);
                y*=y;
                y=y%mod;
                f(j,divisors[x].size())
                {
               ans[divisors[x][j]-1]=(ans[divisors[x][j]-1]-a[x-1]);
               ans[divisors[x][j]-1]=(ans[divisors[x][j]-1]+y);
               while(ans[divisors[x][j]-1]<0)
               {
               	ans[divisors[x][j]-1]+=mod;
    		   }
    		   ans[divisors[x][j]-1]=ans[divisors[x][j]-1]%mod;
                }
                a[x-1]=y;
            }
        }
    }
        
     
    	return 0;
    }  