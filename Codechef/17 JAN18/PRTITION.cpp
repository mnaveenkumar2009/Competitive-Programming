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
            bool we=1;
            ll x=sscan(),n=sscan(),sum;
            sum=n*(n+1);
            sum/=2;
            sum-=x;
            //cout<<sum<<endl;
            if(sum%2){
                printf("impossible\n");
                continue;
            }
            
            int i;
            
            vector <ll> a,b,ans(n,1);
            ll counta=sum/2,countb=sum/2,k=sum/2;
            {
                f(i,n){
                    if(n-i!=x){
                       // cout<<counta<<" "<<(n-i)<<endl;
                    if((counta-(n-i))>=0){
                        if(counta-(n-i)==2){
                            if(x==2){
                                b.pb(n-i);
                                countb-=n-i;
                                continue;
                            }
                        }
                        if(counta-(n-i)==1){
                            if(x==1){
                                b.pb(n-i);
                                countb-=n-i;
                                continue;
                            }
                        }
                        a.pb(n-i);
                        counta-=n-i;
                    }
                    else
                    {
                        b.pb(n-i);
                        countb-=n-i;
                    }
                    }
                }
                ans[x-1]=2;
                if(counta!=0){printf("impossible\n");continue;}
                f(i,a.size())ans[a[i]-1]=0;
                f(i,n)printf("%d",ans[i]);
                printf("\n");
                continue;
            }
            printf("impossible\n");
        }
        
    	return 0;
    } 