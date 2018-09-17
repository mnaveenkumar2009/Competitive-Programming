    #include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
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

int main(){
    int t=uscan();
    while(t--){
        ll n=uscan();
        vector <ll> a(n);
        ll i,j,k;
        ll b[10];
        f(i,n){
            a[i]=uscan();
            b[a[i]-1]=i;
        }
        vector <ll> c(n,-1);
        f(i,n){
            f(j,10){
                if(a[i]+j+1<10)
                    if(b[a[i]+j+1]>i){
                        c[i]=b[a[i]+j+1];
                        break;
                    }
            }
        }
        f(i,n){
            if(c[n-i-1]!=-1){
                swap(a[n-i-1],a[c[n-i-1]]);
                break;
            }
        }
        i=n-i-1;
        sort(a.begin()+,a.end());
    }
}