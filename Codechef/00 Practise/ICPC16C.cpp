    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
    long long powmod(long long base,long long pow)
    {
       long long res=1;
       while(pow)
       {     
             if (pow%2!=0)  res=(res*base)%mod;
             base=(base*base)%mod;
             pow/=2;
       }
       return res;
    }
     
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    	    int d;
    	    cin>>d;
    	    d=d%9;
    	    
    	    printf("%d\n",d+1);
    	}
    	return 0;
    } 