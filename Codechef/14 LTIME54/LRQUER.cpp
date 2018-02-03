//50 points solution
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
     
    int main(){
    	int t;
    	cin>>t;
    	while(t--){
    		int n,q;
    		cin>>n>>q;
    		vector <ll> a(n);
    		bool we=0;
    		int i;
    		f(i,n)
    		{
    			slld(a[i]);
    			if(a[i]>100)we=1;
    		}
    		if(!we){
    			set <int> b[102];
    			f(i,n){
    				b[a[i]].insert(i);
    			}
    			while(q--){
    				int x;
    				sd(x);
    				if(x==1){
    					int l,r;
    					sd(l);
    					sd(r);
    					l--;r--;
    					ll maxi=-1;
    					f(i,101){
    						
    						if(b[i].lower_bound(l)!=b[i].end()){
    							if(*(b[i].lower_bound(l))<=r)
    							{	ll temp=a[r]-i;
    							temp*=(i-a[l]);
    							maxi=max(maxi,temp);
    							}
    						}
    					}
    					printf("%lld\n",maxi);
    				}
    				else
    				{
    					int xx,yy;
    					sd(xx);sd(yy);
    					b[a[xx-1]].erase(b[a[xx-1]].lower_bound(xx-1));
    					a[xx-1]=yy;
    					b[yy].insert(xx-1);
    				}
    			}
    		}
    		else
    		{
    			while(q--){
    				int x;
    				sd(x);
    				if(x==1){
    					int l,r;
    					sd(l);
    					sd(r);
    					l--;r--;
    					ll maxi=-1;
    					for(i=l;i<=r;i++){
    						ll temp=a[r]-a[i];
    						temp*=(a[i]-a[l]);
    						maxi=max(maxi,temp);
    					}
    					printf("%lld\n",maxi);
    				}
    				else
    				{
    					int xx,yy;
    					sd(xx);sd(yy);
    					a[xx-1]=yy;
    				}
    			}
    		}
    		
    	}
    } 