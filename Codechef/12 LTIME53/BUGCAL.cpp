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
    		long long ans=0,a,b;
    		cin>>a>>b;
    		int i=0;
    		while(a!=0||b!=0){
    			ans+=((a%10+b%10)%10)*pow(10,i);
    			a/=10;
    			b/=10;
    			i++;
    		}
    		cout<<ans<<endl;
    	}
    	return 0;
    } 