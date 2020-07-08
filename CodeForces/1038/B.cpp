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
    ll t=1;
    ll kkk=0;
    ios_base::sync_with_stdio(0);
    f(kkk,t){
        ll n=uscan(),i,j;
        if(n==1){
            cout<<"No";
            return 0;
        }
        vector <ll> a(n);
        ll sum=(n*(n+1))/2;
        if(sum%2==0){
            cout<<"Yes\n";
            cout<<"1 2\n";
            cout<<n-1<<' ';
            f(i,n){
                if(i+1!=2){
                    cout<<i+1<<' ';
                }
            }
        }
        else{
            f(i,n){
                if(__gcd(sum-(i+1),i+1)>1){
                    break;
                }
            }
            if(i==n){
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
                cout<<"1 "<<i+1<<'\n';
                ll temp=i+1;
                cout<<n-1<<' ';
                f(i,n){
                    if(i+1!=temp){
                        cout<<i+1<<' ';
                    }
                }
            }

        }
    }
    return 0;
}