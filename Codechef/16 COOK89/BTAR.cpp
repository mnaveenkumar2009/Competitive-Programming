    #include <bits/stdc++.h>
    using namespace std;
    #define f(i,n) for(i=0;i<n;i++)
    #define pb push_back
    #define sd(n) scanf("%d",&n)
    #define sc(n) scanf("%c",&n)
    #define slld(n) scanf("%lld",&n)
    #define mod 1000000007
    #define mp make_pair
    #define ff first
    #define ss second
    #define ll long long
    #define gc getchar
    #define pc putchar
    inline unsigned long long uscan()
    {
        unsigned long long n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
    inline long int lscan()                 
    {
        long int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
     
     
    inline  int sscan()                     
    {register  int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0')
        {
    n=n*10+c-'0';
    c=gc();
        }
    return n;
    }
    int main()
    {
    	int t=sscan(),i;
    	
    	while(t--)
    	{
    		int n=sscan();
    		vector <ll> a(n);
    		f(i,n)a[i]=uscan();
    		ll c[4]={0};
    		f(i,n)c[a[i]%4]++;
    		bool we=1;
    		ll sum=0;
    		f(i,n)sum+=a[i];
    		if(sum%4)we=0;
    		ll ans=0;
    		ans+=c[2]/2;
    		c[2]=c[2]%2;
    		ll temp=min(c[1],c[3]);
    		ans+=temp;
    		c[1]-=temp;
    		c[3]-=temp;
    		ans+=((c[1]+c[3])/4)*3;
    		c[1]=c[1]%4;
    		c[3]%=4;
    		if(c[2])
    		ans+=(c[2]+(c[3]+c[1])-1);
    		
    		if(we){
    			printf("%lld\n",ans);
    		}
    		else
    		{
    			printf("-1\n");
    		}
    	}
    } 