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
    #define ld long double
    #define gc getchar
    #define pc putchar
    inline ll uscan()
    {
        ll n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
    }
    int main()
    {
        int t=uscan();
        while(t--){
            ll n=uscan(),k=uscan();
            if(n==1){
                printf("%lld\n",k);
                continue;
            }
            if(k==1){
                while(n--){
                    putchar('1');putchar(' ');
                }putchar('\n');
                continue;
            }
            ll mak=log2(k);
            mak=1LL<<(mak+1);
            mak=mak-1;
            vector <ll> a;
            ll i=0;
            if(k!=mak){
            a.pb(k);
            a.pb(mak^k);}
            else{
                ll tt=log2(k);
                tt=1<<tt;
                a.pb(tt);
                a.pb(mak^tt);
            }
            //cout<<a[0]<<" "<<a[1]<<endl;
            f(i,n-2){
                a.pb(1);
            }
            if(n%2){
               
                ll xxx=log2(a[0]);
                xxx=1LL<<xxx;
                if(xxx!=a[0]){
                    a[0]=a[0]^xxx;
                    a[n-1]=xxx;
                }
                else{
                    xxx=log2(a[1]);
                    xxx=1LL<<xxx;
                    if(xxx!=a[1]){
                        a[1]=a[1]^xxx;
                        a[n-1]=xxx;
                    }
                }
                 if(k==3)a[0]=3;
            }
            f(i,n){
                printf("%lld ",a[i]);
            }
            putchar('\n');
        }
    	return 0;
    } 