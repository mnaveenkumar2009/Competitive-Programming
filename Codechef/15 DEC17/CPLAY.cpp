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
        char s[20];
        int i;
        string A="TEAM-A ",B="TEAM-B ",T="TIE\n";
        while(scanf("%s",s)==1){
            int ca=0,cb=0,m=0,f=0,r1;
            f(i,20){
                if(i%2==0){
                    if(s[i]-'0'){++ca;}
                    if(!f){
                        r1=i/2+1;
                        if(cb+5-r1+1<ca){f=3;m=i;break;}
                        else if(ca+5-r1<cb){f=4;m=i;break;}
                    }
                }
                else if(i%2==1){
                    if(s[i]=='1'){++cb;}
                    if(f==0){
                        r1=i/2+1;
                        
                        if(cb+5-r1<ca){f=3;m=i;break;}
                        else if(ca+5-r1<cb){f=4;m=i;break;}
                    }
                    else if(f==1){
                        if(ca>cb){m=i;f=3;break;}
                        if(cb>ca){m=i;f=4;break;}
                    }
                }
                if(i==9){f=1;}
            }
            if(f==3){
                cout<<A<<m+1<<endl;
            }
            else if(f==4){
                cout<<B<<m+1<<endl;
            }
            else{
                cout<<T;
            }
        }
    	return 0;
    } 