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
     
    long long powmod(long long base,long long pow,long long modu)
    {
       long long res=1;
       while(pow)
       {     
             if (pow%2!=0)  res=(res*base)%modu;
             base=(base*base)%modu;
             pow/=2;
       }
       return res;
    }
     
    ll gcdExtended(ll a, ll b, ll *x, ll *y)
    {
        if (a == 0)
        {
            *x = 0, *y = 1;
            return b;
        }
     
        ll x1, y1;
        ll gcd = gcdExtended(b%a, a, &x1, &y1);
        *x = y1 - (b/a) * x1;
        *y = x1;
     
        return gcd;
    }
     
    ll modInverse(ll a, ll m)
    {
        ll x, y;
        ll g = gcdExtended(a, m, &x, &y);
        ll res = (x%m + m) % m;
        return res;
        
    }
     
     
     
    int main()
    {
        
    	int t=1;
    	sd(t);
    	while(t--){
    	    int n,k;
    	    bool we=1;
    	    cin>>n>>k;
    	    int a[n],i,up=INT_MAX,lo=0;
    	    f(i,n)sd(a[i]);
    	    if(n>2){
    	        if(a[0]>a[1])up=a[0];
    	        else
    	        lo=a[0];
    	        
    	        for(i=2;i<n;i++){
    	            //cout<<up<<" "<<lo<<endl;
    	            if(a[i]>up||a[i]<lo){we=0;break;}
    	            if(a[i]>a[i-1]){
    	                lo=a[i-1];
    	            }
    	            else
    	            {
    	                up=a[i-1];
    	            }
    	        }
    	        
    	    }
    	    if(a[n-1]!=k)we=0;
    	    if(!we)printf("NO\n");
    	        else
    	        printf("YES\n");
    	}
    	
    	return 0;
    } 