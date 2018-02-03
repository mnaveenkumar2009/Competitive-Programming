    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    int main() {
        int t;
        sd(t);
    while(t--)
    {   
        string s;
        cin>>s;bool we=0;
        int i;
        f(i,s.length()-1)
        {
        	if(s[i]==s[i+1])we=1;
    	}
    	f(i,s.length()-2)
        {
        	if(s[i]==s[i+2])we=1;
    	}
    	if(we)
    	{
    		printf("YES\n");
    	}
    	else
    	{
    		printf("NO\n");
    	}
    }
        
     
    	return 0;
    }  