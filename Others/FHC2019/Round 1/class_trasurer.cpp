#include <bits/stdc++.h>
using namespace std;
// BBBAABBBAAAA
#define ll long long
#define mod 1000000007
ll pr(ll x, ll y)
{
    ll res = 1; 

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}

int main(){
    ll t;
    int kkk=1;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=0;
        ll b=0;
        for(ll i=n;i>=1;i--){
            if(s[i-1]=='A'){
                b--;
                if(b<0)b=0;
            }
            else{
                b++;
                if(b>k){
                    b-=2;
                    s[i-1]='A';
                    ans+=pr(2,i);
                    ans%=mod;
                    if(b<0)b=0;
                }
            }
            // cout<<i <<' '<<b<<'\n';
        }
        cout<<s<<'\n';
        cout<<"Case #"<<kkk++<<": "<<ans<<'\n';
    }
}