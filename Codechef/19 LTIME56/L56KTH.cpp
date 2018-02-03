//30 points solution
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
    #define ld long double 
    int main()
    {
        int n=sscan(),k=sscan();
        int i;
        vector <int> a(n);
        f(i,n)a[i]=sscan();
        vector <int> ans;
        f(i,n){
            ll x=0,mini=INT_MAX; 
            for(int j=i;j<n;j++){
                x = x ^ a[j]; 
                if(a[j]<mini){mini=a[j];}
                ans.pb(x*mini);
            }
        }
        sort(ans.begin(),ans.end());
        printf("%d",ans[k-1]);
    	return 0;
    } 