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
    		string a,b,cc;
    		int i;
    		int c[2]={0};
    		f(i,n){
    			cin>>a;
    			if(i==0)b=a;
    			if(a!=b)cc=a;
    			if(a==b)
    			c[0]++;
    			else
    			c[1]++;
    		}
    		if(c[0]>c[1]){
    			cout<<b<<endl;
    		}
    		else
    		if(c[0]<c[1]){
    			cout<<cc<<endl;
    		}
    		else
    		{
    			cout<<"Draw\n";	
    		}
    	}
    } 