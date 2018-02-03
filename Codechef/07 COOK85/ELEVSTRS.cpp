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
    		double v1,v2;
    		cin>>n>>v1>>v2;
    		v1*=sqrt(2);
    		if(v1<=v2)
    		{
    			printf("Elevator\n");
    		}
    		else
    		{
    			printf("Stairs\n");
    		}
    	}
    	return 0;
    } 