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
        ll maxSubArraySum(ll a[], ll size)
        {
            ll max_so_far = INT_MIN, max_ending_here = 0;
            
            for (int i = 0; i < size; i++)
            {
                //if(size==8)cout<<max_so_far<<" "<<a[i]<<" "<<max_ending_here<<endl;;
                max_ending_here = max_ending_here + a[i];
                if (max_so_far < max_ending_here)
                    max_so_far = max_ending_here;
         
                if (max_ending_here < 0)
                    max_ending_here = 0;
            }
            return max_so_far;
        }
        int main()
        {
            int t=1;
            t=sscan();
            while(t--){
                ll l=0,r;
                ll n=sscan(),k=sscan();
                ll a[n];
                int i;
                f(i,n)scanf("%lld",&a[i]);
                ll aa=maxSubArraySum(a,n);
                if(k==1)
                {printf("%lld\n",aa);continue;}
                ll b[2*n];
                f(i,n){
                    b[i]=a[i];
                    b[i+n]=a[i];
                }
                aa=max(aa,maxSubArraySum(b,2*n));
                ll sum[n];
                f(i,n)sum[i]=a[i];
                f(i,n-1)sum[i+1]+=sum[i];
                r=sum[n-1];
                f(i,n)l=max(l,sum[i]);
                f(i,n)r=max(r,sum[n-1]-sum[i]);
                {
                    ll u=k-2;
                    u*=sum[n-1];
                    u+=l+r;
                    
                    ll ans=max(aa,u);
                    printf("%lld\n",ans);
                }
            }
        	return 0;
        }     