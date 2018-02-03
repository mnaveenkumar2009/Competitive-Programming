    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
     
    int main()
    {
    	int t;
    	sd(t);
    	while(t--)
    	{
    		string s;
    		int i;
    		long long a[26];
    		int count[26];
    		f(i,26)
    		{count[i]=0;
    			slld(a[i]);
    		}
    		cin>>s;
    		f(i,s.length())
    		{
    			count[s[i]-'a']++;
    		}
    		long long ans=0;
    		f(i,26)
    		{	//cout<<count[i]<<endl;
    			if(!count[i])ans+=a[i];
    		}
    	cout<<ans<<endl;
    	}	
    	
    	return 0;
    } 