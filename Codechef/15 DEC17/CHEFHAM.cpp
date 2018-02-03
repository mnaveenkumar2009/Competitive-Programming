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
     
    vector <int> a(100005,0);
    int main() {
        int t=sscan();
        while(t--){
            int n=sscan(),i;
            f(i,n)a[i+1]=sscan();
            if(n==1){
                printf("0\n%d\n",a[1]);
            }
            else
            if(n==2){
                if(a[1]==a[2]){
                    printf("0\n%d %d\n",a[2],a[1]);
                }
                else
                printf("2\n%d %d\n",a[2],a[1]);
            }
            else if(n==3){
                if(a[1]==a[2]||a[1]==a[3]||a[2]==a[3]){
                    printf("2\n");
                }
                else{
                    printf("3\n");
                }
                printf("%d %d %d\n",a[2],a[3],a[1]);
            }
            else{
            printf("%d\n",n);
            int tt=0,r[3][3];
            a[0]=a[n];
            f(i,n){
                if(a[i]==a[i+1]){
                    if(tt==0){
                        tt=1;
                        r[0][0]=i;
                        r[0][1]=a[i];
                        continue;
                    }
                    if(tt==1){
                        a[r[0][0]]=a[i];
                        a[i]=r[0][1];
                        tt=0;
                    }
                }
            }
            if(tt==1){
                if(a[(r[0][0]+1)%n]!=r[0][1]){
                    swap(a[(r[0][0]+1)%n],a[r[0][0]]);
                }
                else{
                    swap(a[(r[0][0]+2)%n],a[r[0][0]]);
                }
            }
            f(i,n){
                printf("%d ",a[i]);
            }
            printf("\n");
                
            }
        }
    	return 0;
    } 