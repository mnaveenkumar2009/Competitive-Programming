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
        int t=sscan();
        while(t--){
            int j,n=sscan();
            vector <ll> a[n];
            
            int i;
            f(i,n)a[i].resize(n,0);
            f(i,n){
                f(j,n)
                a[i][j]=uscan();
                sort(a[i].begin(),a[i].end());
            }
            bool we=1;
            ll ans=0,temp=INT_MAX;
            f(i,n){
                f(j,n){
                    if(a[n-i-1][n-j-1]<temp){temp=a[n-i-1][n-j-1];break;}
                }
                if(j==n)we=0;
                ans+=temp;
            }
            if(we){
                printf("%lld\n",ans);
            }
            else
            printf("-1\n");
        }
        
    	return 0;
    } 