#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll long long

vector <ll> primeFactors(ll n) 
{
    vector <ll> a;
    while (n%2 == 0) 
    { 
        a.pb(2);
        n = n/2; 
    }
    for (ll i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
            a.pb(i);
            n = n/i; 
        } 
    }
    if (n > 2) 
        a.pb(n);

    return a;
} 
ll f2(ll val,ll b,vector <ll> a){
    ll ans=INT_MAX;
    for(auto bb:a){
        ll b2=b;
        ll c=0;
        while(b2%bb==0){
            c++;
            b2/=bb;
        }
        ll sn=0;
        for(ll i=bb;i<1e16;i*=bb){
            sn+=val/i;
        }
        ans=min(ans,sn/c);
    }
    return ans;
}
int main()
{
    ll t,n,b;
    cin>>t;
    while(t--){
        cin>>b>>n;
        vector <ll> a=primeFactors(b);
        // sort(a.begin(),a.end());
        // b=a[a.size()-1];
        ll sn,low=0,high=1e16;
        
        while(low!=high){
            cout<<low<<' '<<high<<'\n';
            ll mid=(low+high)/2;
            sn=f2(mid,b,a);
            cout<<sn<<'\n';
            if(sn<n){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        cout<<low<<'\n';
        sn=f2(low,b,a);
        // cout<<sn<<'\n';
        if(sn!=n){
            cout<<"-1\n";
        }
        else
            cout<<low<<'\n';
    }
    return 0;
}