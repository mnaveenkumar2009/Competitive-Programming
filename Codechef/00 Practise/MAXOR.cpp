#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll long long
int main()
{
    ll t,kkk;
    cin>>t;
    
    f(kkk,t){
        ll n,i,j,x;
        cin>>n;
        vector<ll> dp((1LL<<22),0),c(1000008,0);
        f(i,n){cin>>x;dp[x]++;c[x]++;}
        ll ans=0;
        f(i,22){
            f(j,(1LL<<22)){
                if((1LL<<i)&j)
                    dp[j]+=dp[j^(1LL<<i)];
            }
        }
        //f(i,10)cout<<dp[i]<<' ';
        f(i,1000008){
            ans+=((2*dp[i]-c[i]-1)*c[i])/2;
        }
        cout<<ans<<'\n';
    }
	return 0;
}


