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
        
    	int t=sscan() ;
    	while(t--){
    	    ll x=uscan();
    	    ll y=uscan();
    	    ll z=uscan();
    	    if(x>y)swap(x,y);
    	    if(x>z)swap(x,z);
    	    if(y>z)swap(y,z);
    	   // cout<<x<<" "<<y<<" "<<z<<endl;
    	    //x<=y<=z
    	    
    	    ll a=uscan();
    	    ll b=uscan();
    	    ll c=uscan();
    	    ll ans=0,A=6*a,B=3*b,C=2*c;
    	    if(A<=B&&A<=C){
    	        ans=(x+y+z)*a;
    	        x=0;
    	        y=0;
    	        z=0;
    	    }
    	    else
    	    {
    	        if(B<=A&&B<=C){
    	            ans=(y-x)*b;
    	            z=x+(z-y);
    	            y=x;
    	            //x-- z-=2
    	            ll diff=z-x;
    	            diff/=2;
    	            diff*=2;
    	            if(x>diff){
    	                x-=diff;
    	                y-=diff;
    	                z-=diff*2;
    	                ans+=(diff*2*b);
    	            }
    	            else
    	            {
    	               ans+=(b*x*2);
    	               z-=x*2;
    	               x=0;
    	               y=0;
    	            }
    	            //cout<<x<<" "<<y<<' '<<z<<endl;
    	            // only z is left or x x x+1 or x x x
    	            if(!x){
    	                ans+=z*a;
    	                z=0;
    	            }
    	            //cout<<x<<" "<<y<<' '<<z<<endl;
    	            // 0 0 0 or x x x+1 or x x x
    	            if(x|y|z){
    	                ll rem=x+y+z;
    	                if(rem%2){
    	                    x=1;
    	                    y=1;
    	                    z=1;
    	                    ans+=((rem-3)/2)*b;
    	                }
    	                else
    	                {
    	                    ans+=(rem/2)*b;
    	                    x=0;y=0;z=0;
    	                }
    	                if(x)
    	                ans+=min(b+a,c);
    	                x=0;
    	                y=0;
    	                z=0;
    	            }
    	            
    	            
    	        }
    	        else
    	        {
    	            if(A<=B){
    	                ans=c*x;
    	                y-=x;
    	                z-=x;
    	                x=0;
    	                ans+=a*(y+z);
    	                y=0;
    	                z=0;
    	            }
    	            else
    	            {
    	                ll cop=x,bop=y-x,aop=z-y;
    	                if(2*b<a+c){
    	                    ll remm=min(cop,aop);
    	                    bop+=2*remm;
    	                    aop-=remm;
    	                    cop-=remm;
    	                }
    	                ans=cop*c;
    	                ans+=bop*b;
    	                ans+=aop*a;
    	                x=0;
    	                y=0;
    	                z=0;
    	            }
    	        }
    	    }
    	    printf("%lld\n",ans);
    	}
    	
    	return 0;
    } 