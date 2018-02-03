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
     
    int main() {
        int t=sscan();
        while(t--){
            ll n=uscan(),m=uscan(),i,j,m1=0,m2=0;
            char ch;
            f(i,n){
                f(j,m){
                    ch=getchar();
                    if(ch=='\n')ch=getchar();
                   // cout<<ch;
                    if((i+j)%2==0){
                        if(ch!='R')m1+=3;
                        if(ch!='G')m2+=5;
                    }
                    else{
                        if(ch!='G')m1+=5;
                        if(ch!='R')m2+=3;
                    }
                }
               // cout<<endl;
            }
            printf("%d\n",min(m1,m2));
        }
    	return 0;
    } 