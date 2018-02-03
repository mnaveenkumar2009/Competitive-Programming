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
     
    int a[1000][1000],n,m;
    bool val(int i,int j){
        if(i<0||i>=n)return 0;
        if(j<0||j>=m)return 0;
        if(a[i][j]==-2)return 0;
        return 1;
    }
    void f2(int i,int j){
        if(val(i-1,j)){
            a[i][j]=max(a[i-1][j]-1,a[i][j]);
        }
        if(val(i,j-1)){
            a[i][j]=max(a[i][j-1]-1,a[i][j]);
        }
        if(val(i+1,j)){
            a[i][j]=max(a[i+1][j]-1,a[i][j]);
        }
        if(val(i,j+1)){
            a[i][j]=max(a[i][j+1]-1,a[i][j]);
        }
    }
    int main()
    {
        int t=1;
        t=sscan();
        while(t--){
            n=sscan();
            m=sscan();
            char ans[n][m];
            int i,j;
            f(i,1000)f(j,1000){a[i][j]=-1;}
            f(i,n){
                f(j,m){
                    int temp;
                    sd(temp);
                    if(temp==-1){
                        a[i][j]=-2;
                    }
                    else
                        if(temp!=0){
                            a[i][j]=temp;
                        }
                }
            }
            f(i,n){
                f(j,m){
                    if(val(i,j))f2(i,j);
                }
            }
            f(i,n){
                f(j,m){
                    if(val(n-i-1,m-j-1))f2(n-i-1,m-j-1);
                }
            }
            f(i,n){
                f(j,m){
                    if(val(i,j))f2(i,j);
                }
            }
            f(i,n){
                f(j,m){
                    if(val(n-i-1,m-j-1))f2(n-i-1,m-j-1);
                }
            }
            f(j,m){
                f(i,n){
                    if(val(i,j))f2(i,j);
                }
            }
            f(j,m){
                f(i,n){
                    if(val(n-i-1,m-j-1))f2(n-i-1,m-j-1);
                }
            }
            f(j,m){
                f(i,n){
                    if(val(i,j))f2(i,j);
                }
            }
            f(j,m){
                f(i,n){
                    if(val(n-i-1,m-j-1))f2(n-i-1,m-j-1);
                }
            }
            /*f(i,n){
                f(j,m){
                    if(a[i][j]>0)f2(a[i][j],i,j);
                }
            }*/
           /*
            f(i,n){
                f(j,m){
                    printf("%d ",a[i][j]);
                }cout<<endl;
            }*/
            f(i,n){
                f(j,m){
                    if(a[i][j]==-2)ans[i][j]='B';
                    if(a[i][j]==-1)ans[i][j]='N';
                    if(a[i][j]>=0)ans[i][j]='Y';
                }
            }
            f(i,n){
                f(j,m){
                    putchar(ans[i][j]);
                }pc('\n');
            }
        }
    	return 0;
    } 