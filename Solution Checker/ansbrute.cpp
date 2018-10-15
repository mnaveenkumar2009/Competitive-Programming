#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,a,n) for(long long i=a;i<=n;++i)
#define repb(i,n,a) for(long long i=n;i>=a;--i)
#define dbg1(a,b,c) cout<<"\n->"<<a<<" "<<b<<" "<<c<<"\n"; 
#define dbg2(a,b,c) cout<<"\n--"<<a<<" "<<b<<" "<<c<<"\n"; 
using namespace std;

typedef long long ll;
typedef long double ld;

ll mod=(ll)1e9+7;
ll num[50005];
ll tests,fre[1000005];
ll r1,r2,r3,r4,r5,r6,r7,r8,r9;

ll Mul(ll a, ll b, ll M){
    ll res = 0;
    const int k = 14;// floor(64 - log2(MAX_VALUE))
    while (a > 0) {
        int intA = a & ((1 << k) - 1);
        res = (res + b * intA) % M;
        a >>= k;
        b = (b << k) % M;
    }
    return res;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // num
    num[1]=1;
    rep(i,2,50000){
        num[i]=Mul((2*i)-1,num[i-1],mod);
        // num[i]=((2*i-1)*num[i-1])%mod;
    }

    cin>>tests;
    while(tests--){
        vector<ll> a;
        ll n;
        cin>>n;
        memset(fre,0,sizeof(fre));
        rep(i,1,n){cin>>r1;++fre[r1];}
        repb(i,1000000,1){
            if(fre[i]) a.pb(fre[i]);
            // if(fre[i]) cout<<fre[i]<<" ";
        }
        // cout<<"<-\n";
    
        ll uptil=a.size();
        ll ans=1;
        rep(i,0,uptil-2){
            if(a[i]==0) continue;
            if(a[i]==1){
                ans=Mul(ans,a[i+1],mod);
                // ans=(ans*a[i+1])%mod;
                --a[i+1];
                continue;
            }
            if(a[i]&1){
                ans=Mul(ans,a[i],mod);
                ans=Mul(ans,a[i+1],mod);
                ans=Mul(ans,num[(a[i]-1)/2],mod);
                // ans=(ans*(a[i])*num[(a[i]-1)/2]*a[i+1])%mod;
                a[i+1]-=1;
            }
            else{
                ans=Mul(ans,num[a[i]/2],mod);
                // ans=(ans*num[a[i]/2])%mod;
            }
        }
        if(a[uptil-1]){
            ans=Mul(ans,num[a[uptil-1]/2],mod);
        } 
            // ans=(ans*num[a[uptil-1]/2])%mod;
        cout<<ans<<"\n";
    }
	return 0;
}