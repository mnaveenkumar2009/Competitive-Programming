    #include<bits/stdc++.h>
     
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    using namespace std;
    int main()
    {
    	int i,j,n,m;
    	int t;
    	sd(t);
    	while(t--)
    	{
    		long long a,b,k;
    		cin>>k>>a>>b;
    		long long dif = abs(b-a);
    		
    		if(dif> abs( k-dif) )
    		dif=abs( k-dif);
    		//cout<<dif<<endl;
    		if((dif!=k/2||k%2))
    		{
    			printf("%lld\n",dif-1);
    		}
    		else
    		{
    			printf("0\n");
    		}
    	}
    	return 0;
    } 