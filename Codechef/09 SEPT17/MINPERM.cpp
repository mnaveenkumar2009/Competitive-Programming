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
    		vector <int> a(n+1);
    		int i;
    		f(i,n)
    		a[i]=i+1;
    		for(i=0;i<n;i+=2)
    		{  int t=a[i];
    			a[i]=a[i+1];
    			a[i+1]=t;
    		}
    		if(n%2)
    		{
    			a[n-1]=a[n-2];
    			a[n-2]=n;
    		}
    		f(i,n)printf("%d ",a[i]);
    		cout<<endl;
    	}
    	return 0;
    } 