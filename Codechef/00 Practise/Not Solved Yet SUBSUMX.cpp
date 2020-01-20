#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define mod 1000000007
#define ll long long
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
    return n+(-2*check*n);
}
#define sc uscan()

#define vl vector <ll>
#define N 106
ll choose[N][N];
ll f2(vl &a,vl &b){
        // for(auto it:a){
        //     cout<<it<<' ';
        // }pc('\n');
        // for(auto it:b){
        //     cout<<it<<' ';
        // }pc('\n');
    ll i,aa=0,bb=0;
    f(i,64){
        aa+=(1LL<<i)*a[i];
        bb+=(1LL<<i)*b[i];
    }
    
    if(aa<bb){
        return 0;
    }
    if(aa==bb)
        return 1;
    if(bb==0)return 1;
    ll ret=0;
    f(i,64){
        if(b[i]){
            f(j,i){
                a[j+1]+=a[j]>>1;
            }
            // for(ll tak=0;tak<=min(a[63-i],b[63-i]);tak++){
                vector <ll> newb=b;
                vector <ll> newa=a;
                newb[63-i]-=tak;
                if(63-i-1>=0){
                    newb[63-i-1]+=newb[63-i]<<1;
                }
                else{
                    if(newb[63-i]){
                        continue;
                    }
                }
                newa[63-i]=0;
                newb[63-i]=0;
                ret=(ret+f2(a,b)*choose[a[i]][tak])%mod;
            // }
            break;
        }
    }
    // f(i,64){
    //     if(b[63-i]){
    //         // cout<<i<<'\n';
    //         for(ll tak=0;tak<=min(a[63-i],b[63-i]);tak++){
    //             vector <ll> newb=b;
    //             vector <ll> newa=a;
    //             newb[63-i]-=tak;
    //             if(63-i-1>=0){
    //                 newb[63-i-1]+=newb[63-i]<<1;
    //             }
    //             else{
    //                 if(newb[63-i]){
    //                     continue;
    //                 }
    //             }
    //             newa[63-i]=0;    
    //             newb[63-i]=0;
    //             ret=(ret+f2(newa,newb)*choose[a[63-i]][tak])%mod;
    //         }
    //         break;
    //     }
    // }
    return ret;
}
int main()
{
    ll t;

	choose[0][0] = 1;
	for(int i=1; i<N; i++) {
		choose[i][0] = choose[i][i] = 1;
		for(int j=1; j<i; j++)
			choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % mod;
	}
    
    t=sc;
    while(t--){
        ll n=sc,i,j,k=sc;
        vl a(64,0),b(64,0);
        f(i,n){
            a[sc]++;
        }
        f(i,64){
            if((1LL<<i)&k)b[i]++;
        }
        cout<<f2(a,b)<<'\n';
    }
    return 0;
}