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


const ll N = 1e5;
ll n; 
ll t[6][2 * N];

void modify(ll l,ll r, ll p) {
  for (t[p][l += n] +=1 ; l > 1; l >>= 1) t[p][l>>1] = t[p][l] + t[p][l^1];

  if(r!=n){
      for (t[p][r += n] -=1 ; r > 1; r >>= 1) t[p][r>>1] = t[p][r] + t[p][r^1];
  }
}

ll query(ll l, ll r,ll p) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    // cout<<l<<' '<<r<<' '<<p<<' '<<res<<'\n';
    if (l&1) res += t[p][l++];
    if (r&1) res += t[p][--r];
  }
  return res;
}


int main()
{
    ll i,j;
    f(i,6)f(j,2*N)t[i][j]=0;
    n=uscan();
    ll a[n];
    f(i,n)a[i]=uscan();
    ll m=uscan();
    while(m--){
        ll l,r,p;
        if(uscan()==1){
            l=uscan();
            r=uscan();
            p=uscan();
            modify(l-1,r,p);
        }
        else{
            l=uscan();
            r=l;
            l--;
            p=uscan();
            a[l]=p;
            p=2;
            ll sdhg=query(0,l+1,p);
            for (t[p][l += n] -=sdhg ; l > 1; l >>= 1) t[p][l>>1] = t[p][l] + t[p][l^1];
            if(r!=n){
              for (t[p][r += n] +=sdhg ; r > 1; r >>= 1) t[p][r>>1] = t[p][r] + t[p][r^1];
            }
            p=3;
            r=l+1;
            sdhg=query(0,l+1,p);
            // cout<<sdhg<<' '<<t[p][l + n]<<' '<<l<<' '<<r<<' '<<p<<'\n';
            for (t[p][l += n] -=sdhg ; l > 1; l >>= 1) t[p][l>>1] = t[p][l] + t[p][l^1];
            if(r!=n){
              for (t[p][r += n] +=sdhg ; r > 1; r >>= 1) t[p][r>>1] = t[p][r] + t[p][r^1];
            }
            p=5;
            sdhg=query(0,l+1,p);
            r=l+1;
            for (t[p][l += n] -=sdhg ; l > 1; l >>= 1) t[p][l>>1] = t[p][l] + t[p][l^1];
            if(r!=n){
              for (t[p][r += n] +=sdhg ; r > 1; r >>= 1) t[p][r>>1] = t[p][r] + t[p][r^1];
            }

            // f(i,2*n)cout<<t[2][i]<<' ';cout<<'\n';
            // f(i,2*n)cout<<t[3][i]<<' ';cout<<'\n';
            // f(i,2*n)cout<<t[5][i]<<' ';cout<<'\n';
        }


    }
    f(i,n){
        ll ttt=query(0,i+1,2);
        while(a[i]%2==0&&ttt--){
            a[i]/=2;
        }
        ttt=query(0,i+1,3);
        while(a[i]%3==0&&ttt--){
            a[i]/=3;
        }
        ttt=query(0,i+1,5);
        while(a[i]%5==0&&ttt--){
            a[i]/=5;
        }
    }

    f(i,n)cout<<a[i]<<' ';
	return 0;
}
