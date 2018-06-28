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

int main(){
    int n=uscan(),m=uscan();
    int i,j,k;
    char a[n][m];
    f(i,n){
        f(j,m){
            cin>>a[i][j];
        }
    }
    bool doner[n],donec[m];
    f(i,n){
        doner[i]=1;
    }
    f(i,m)donec[i]=1;
    int hh=50;
    while(hh--){
    f(i,n){
        vector <int> r,c;
        f(j,m){
            if(a[i][j]=='#'){
                if(donec[j]){
                    c.pb(j);
                }
            }
        }

        f(k,n){
            bool we=1;
            f(j,m){
                if(a[i][j]=='#'&&a[k][j]!='#')
                we=0;
            }
            if(we){
                if(doner[k]){
                    r.pb(k);
                }
            }
        }
        f(j,r.size())
        {
            f(k,c.size()){
                a[r[j]][c[k]]='.';
                doner[r[j]]=0;
                donec[c[k]]=0;
                //cout<<r[j]<<" "<<c[k]<<endl;
                
            }
        }
        //cout<<endl;
    }
    }
    bool we=1;
    //f(i,n)cout<<doner[i]<<" ";cout<<endl;
    //f(i,m)cout<<donec[i]<<" ";cout<<endl;
    f(i,n){
        f(j,m){
            //cout<<a[i][j];
            if(a[i][j]=='#')we=0;
        }
        //cout<<endl;
    }
    if(we){
        printf("Yes\n");
    }
    else{
        printf("No\n");

    }
    return 0;
}