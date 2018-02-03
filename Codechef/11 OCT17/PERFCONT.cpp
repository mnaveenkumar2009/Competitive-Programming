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
    	    int n,p;
    	    cin>>n>>p;
    	    int a=0,b=0;
    	    while(n--){
    	        int i;
    	        sd(i);
    	        if(i<=p/10)b++;
    	        if(i>=p/2)a++;
    	    }
    	    if(a==1&&b==2)printf("yes\n");
    	    else
    	    printf("no\n");
    	}
    	return 0;
    } 