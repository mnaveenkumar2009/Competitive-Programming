#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}


int main() {
    ll t=1,kkk=0;
    f(kkk,t){
        int n=uscan(),m=uscan();
        // cout<<n<<' '<<m<<'\n';
        ll i,j;
        char a[n][m];
        f(i,n){
            string x;
            cin>>x;
            // cout<<x<<'\n';
            f(j,m){
                a[i][j]=x[j];
                // cout<<a[i][j]<<' ';
            }
        }
        f(i,n){
            bool we=0;
            f(j,m){
                // cout<<a[i][j]<<' ';
                if(a[i][j]=='B'){we=1;break;}
            }
            if(we)break;
        }
        // cout<<i<<' '<<j<<'\n';
        ll i2=i,j2=j;
        for(;j<m;j++){
            if(a[i][j]!='B')break;
        }
        ll len=j-j2;
        cout<<i2+1+len/2<<' '<<j2+1+len/2<<'\n';
    }
    return 0;
}