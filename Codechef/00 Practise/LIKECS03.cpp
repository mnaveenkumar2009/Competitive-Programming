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
    	    int n,k;
    	    int i;
    	    cin>>n>>k;
    	    vector <long long> a(n);
    	    vector <bool> che(k);
    	    f(i,n)
    	    {
    	        slld(a[i]);
    	        int u=log2(a[i]);
    	        if((1LL<<u)==a[i])che[u]=1;
    	    }
    	    int count=0;
    	    f(i,k)
    	    {
    	        if(!che[i])count++;
    	    }
    	    cout<<count<<endl;
    	}
    	return 0;
    } 