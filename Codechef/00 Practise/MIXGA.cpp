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
int main() {
    int t=uscan();
    while(t--){
        ll n=uscan(),k=uscan(),i;
        vector <ll> a(n);
        f(i,n){
            a[i]=uscan();
        }
        ll v=0;
        f(i,n){ 
            if(i%2){
                //minimise
                if(v>=0){
                    v-=a[i];
                }
                else{
                    v+=a[i];
                }
            }
            else{
                //maximise
                if(v>=0)
                    v+=a[i];
                else
                    v-=a[i];
            }
        }
        if(abs(v)>=k)
            cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0;
}
