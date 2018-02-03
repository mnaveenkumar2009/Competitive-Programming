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
    #define gc getchar_unlocked
    #define pc putchar_unlocked
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
     
    ll f2(ll x){
        ll aa=0,r;
        while(x>0){
            r=x%10;
            if(r%2==0){
                aa+=r;
            }
            else{
                aa-=r;
            }
            x/=10;
        }
        return abs(aa);
    }
    vector <ll> ans(1000008);
    vector <ll> temp(2000008);
    int main() {
        int t=sscan(),i;
        temp[2]=2;
        f(i,2000008-5)temp[i+3]=temp[i+2]+f2(i+3);
        ans[1]=2;
        f(i,1000000){
            ans[i+2]=ans[i+1]+2*(temp[2*(i+2)]-temp[i+2])-f2(2*(i+2));
        }
        while(t--){
            ll n;
            n=uscan();
            printf("%lld\n",ans[n]);
        }
    	return 0;
    } 