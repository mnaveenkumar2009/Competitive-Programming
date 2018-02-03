 
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
    		ll n,q;
    		slld(n);
    		slld(q);
    		int i;
    		bool we=1;
    		vector <ll> a(n);
    		ll prod=1,prev=1;
    		f(i,n){
    			slld(a[i]);
    			prev=prod;
    			prod*=a[i];
    			if(prod<prev)we=0;
    		}
    		f(i,q){
    			ll x;
    			slld(x);
    			if(we){
    				printf("%lld ",x/prod);
    			}
    			else{
    				printf("0 ");
    			}
    		}
    		printf("\n");
    	}
    } 