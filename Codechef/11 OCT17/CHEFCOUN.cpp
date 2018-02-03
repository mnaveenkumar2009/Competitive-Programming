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
    	    long long n;
    	    cin>>n;
    	    long long k= 1LL<<32;//4,294,967,295
    	    k-=100;
    	    long long y = k/(n-1);
    	    int count=k%(n-1);
    	    //cout<<count<<endl;
    	    printf("1 ");
    	    int i;
    	    //cout<<y<<endl;
    	    //cout<<k<<endl;
    	    //cout<<(k-y*(n-1))<<endl;
    	    f(i,n-1)printf("%lld ",i<count?(y+1):y);
    	    printf("\n");
    	}
    	return 0;
    } 