    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
     
    int main()
    {
    	int t=1;
    	cin>>t;
    	while(t--){
    		long long y,ans=0;
    		cin>>y;
    		
    		int i;
    		f(i,700){
    			if(y-i-1>0)
    			ans+=sqrt(y-i-1);
    		}
    		cout<<ans<<endl;
    	}
    	return 0;
    } 

