    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
     
    long long powmod(long long base,long long pow)
    {
       long long res=1;
       while(pow)
       {     
             if (pow%2!=0)  res=(res*base)%mod;
             base=(base*base)%mod;
             pow/=2;
       }
       return res;
    }
     
    int main()
    {
    	int t=1;
    	while(t--){
    		vector <long long> fact(20000008);
        fact[0]=1;
        fact[1]=1;
        int i;
    		for(i=2;i<20000008;i++)
            fact[i]=(i*fact[i-1])%mod;
            
    		long long count[4]={0,0,0,0};
    		string s;
    		cin>>s;
    		int n=s.length();
    		f(i,n)
    		{
    			if(s[i]=='L')
    			{
    				count[0]++;
    			}
    			if(s[i]=='R')
    			{
    				count[1]++;
    			}
    			if(s[i]=='U')
    			{
    				count[2]++;
    			}
    			if(s[i]=='D')
    			{
    				count[3]++;
    			}
    		}
    		int q;
    		cin>>q;
    		while(q--)
    		{
    			long long x1,x2,y1,y2,x,y;
    			slld(x1);
    			slld(y1);
    			slld(x2);slld(y2);
    			x=x1-x2;
    			y=y1-y2;
    			long long left=count[0],right=count[1],up=count[2],down=count[3];
    			bool we=0;
    			if(x<0)
    			{
    				if(right +x<0)we=1;
    			}
    			else
    			{
    				if(left-x<0)we=1;
    			}
    			if(y<0)
    			{
    				if(up+y<0)we=1;
    			}
    			else
    			{
    				if(down-y<0)we=1;
    			}
    			if(we)
    			{
    			    printf("0\n");
    			    continue;
    			}
    		
    			long long ans1,ans2;
    			ans1=fact[(left+right)%mod];
    			long long b= (fact[left-x]*fact[right+x])%mod;
        		b= powmod(b,1000000005);
        		ans1 = ans1*b;
        		ans1%=mod;
        		ans2=fact[(up+down)%mod];
    			b= (fact[up+y]*fact[down-y])%mod;
        		b= powmod(b,1000000005);
        		ans2 = ans2*b;
        		ans2%=mod;
    			long long ans=(ans1*ans2)%mod;
    			
    			printf("%lld\n",ans);
    		}
    	}
    	return 0;
    } 