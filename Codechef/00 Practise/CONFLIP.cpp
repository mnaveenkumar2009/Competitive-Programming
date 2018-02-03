    #include <bits/stdc++.h>
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    using namespace std;
    int main()
    {
    	int t;
    	
    	scanf("%d",&t);
    	while(t--)
    	{int g;
    	    cin>>g;
    	    while(g--)
    	    {
    	       int i,q;
    	       long long n;
    	       cin>>i>>n>>q;
    	       if(i==q)
    	       {
    	           cout<<n/2<<endl;;
    	           
    	       }
    	       else
    	       {
    	           cout<<(n/2)+(n%2)<<endl;
    	       }
    	    }
    	}
    return 0;
    } 