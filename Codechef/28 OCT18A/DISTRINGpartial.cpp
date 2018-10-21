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
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
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
#define sc uscan()

int main()
{
    ll n=sc,m=sc;
    vvl a(n,vl (m));
    
    vector <vector <vector <bool > > > xxx(n,vector <vector <bool > >(n,vector <bool > (m,0)));
    ll i,j,k;
    ll ans=0;

    f(i,n){
        f(j,n){
            if(j>=i)
                ans+=((j-i+1)*m*(m+1))/2;
        }
    }
    
    f(i,n){
        f(j,m){
            a[i][j]=sc;
        }
    }
    
    f(i,n){
        vector <vector <bool> > done(m,vector <bool>(m+5,0));
        f(j,n){
            if(j>i){
                // row i,j
                ll temp=0;
                ll cn=0;
                f(k,m){
                    if(a[i][k]==a[j][k]){
                        cn++;
                        ll xyz=1;
                        ll kkkkk;
                        f(kkkkk,cn){
                            if(!done[k][kkkkk+1])
                                temp+=(i+1-0)*(n-j);
                            done[k][kkkkk+1]=1;
                        }
                    }
                    else{
                        cn=0;
                    }
                }
                ans-=temp;
            }
        }
    }
    cout<<ans;
    return 0;
}