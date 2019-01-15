#include <bits/stdc++.h>

using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector <ll> a(n),b(n);
    ll i,j;
    f(i,n){
        cin>>a[i]>>b[i];
    }
    ll dis[n][n];
    f(i,n)f(j,n)dis[i][j]=0;
    f(i,n){
        for(j=i+1;j<n;j++){
            dis[i][j]=max(dis[i][j-1],(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        ll ans=0;
        for(ll cur=l;cur<=r;cur++)
            ans=max(ans,dis[cur][r]);
        cout<<ans<<'\n';
    }
}