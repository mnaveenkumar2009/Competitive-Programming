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
#define sc uscan()
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
    ll t=sc;
    ll kkk=0;
    ios_base::sync_with_stdio(0);
    f(kkk,t){
        ll n=sc,i,j,k;
        vector <ll> a(n);
        vector <vector <ll> > pri(100005,vector <ll> (50,0));
        f(i,n){
            a[i]=sc;
            for(j=2;j<=sqrt(a[i]);j++){
                ll count=0;
                while(a[i]%j==0){
                    a[i]/=j;
                    count++;
                }
                pri[j][count]++;
            }
            if(a[i]!=1){
                pri[a[i]][1]++;
            }
        }
        f(i,10){
            f(j,5){
                cout<<a[i][j]<<' ';
            }pc('\n');
        }
        f(i,100005){
            f(j,50){
                
            }
        }
    }
    return 0;
}