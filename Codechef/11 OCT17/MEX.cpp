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
    	    sd(n);sd(k);
    	    int a[n];
    	    vector <bool> b(200005,0);
    	    int i,ans;
    	    f(i,n){sd(a[i]);b[a[i]]=1;}
    	    //f(i,n)cout<<a[i]<<b[i];
    	    //cout<<endl;
    	    //cout<<k<<endl;
    	    f(i,200005){
    	        if(!b[i]){
    	            k--;
    	            if(k==-1){
    	                ans=i;break;
    	            }
    	        }
    	    }
    	    cout<<ans<<endl;
    	}
    	return 0;
    } 