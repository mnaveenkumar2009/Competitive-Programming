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
    	    cin>>n>>k;
    	    string s;
    	    int i;
    	    f(i,n)s.pb('a');
    	    f(i,n/k){
    	        
    	        if(k%2){
    	            s[i*k+(k/2)]='b';
    	        }
    	        else
    	        {
    	           s[i*k+(k/2)]='b';
    	           s[i*k+(k/2)-1]='b';
    	        }
    	    }
    	    f(i,n){
    	        if(s[i]=='a')break;
    	    }
    	    if(i==n){
    	        printf("impossible\n");
    	    }
    	    else
    	    cout<<s<<endl;
    	}
    	
    	return 0;
    } 