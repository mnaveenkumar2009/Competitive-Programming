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
    	int t;
    	sd(t);
    	while(t--)
    	{
    		int n;
    		sd(n);
    		vector <int> a(n);
    		int i;
    		f(i,n)sd(a[i]);
    		int mini=INT_MAX;
    		f(i,n)
    		{
    			mini=min(mini,a[i]);
    		}
    		f(i,n)
    		{
    			if(mini==a[i])break;
    		}
    		printf("%d\n",i+1);
    	}
    	return 0;
    } 