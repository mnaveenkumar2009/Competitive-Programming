#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll int
#define gc getchar
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
    return n-(2*check*n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,m,i,j,a[100002],nex[100002],cnt[100002],las[100002];
    n=uscan(),m=uscan();
    ll rn=sqrt(n);
    f(i,n){
        a[i]=uscan();
    }
    f(j,n){
        i=n-j-1;
        ll cur=i+a[i];
        cnt[i] = 1;
        while((cur/rn)==(i/rn)&&cur<n){
            cnt[i]++;
            cur+=a[cur];
        }
        nex[i]=cur;
        if(i+a[i]<min(n,(i/rn+1)*rn))
            las[i]=las[i+a[i]];
        else
            las[i]=i;
        
    }

    while(m--){
        if(uscan()){
            ll A=uscan()-1;
            ll ans=0;
            while(nex[A]<n){
                ans+=cnt[A];
                A=nex[A];
            }
            cout<<las[A]+1<<' '<<ans+cnt[A]<<'\n';
        }
        else{
            ll A=uscan()-1,B=uscan();
            a[A]=B;
            B=(A/rn)*rn;
            for(i=A;i>=B;i--){
                if (i+a[i]<min(n,(i/rn+1)*rn)){
                    nex[i]=nex[i+a[i]];
                    las[i]=las[i+a[i]];
                    cnt[i]=cnt[i+a[i]]+1;
                }
                else {
                    nex[i]=i+a[i];
                    las[i]=i;
                    cnt[i]=1;
                }
            }

        }
     //f(i,n)        cout<<nex[i]<<' '<<cnt[i]<<'\n';
    }
	return 0;
}