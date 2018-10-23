#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll long long


int main()
{
    ll t,n,b;
    cin>>n;
    ll i,j,k;
    vector <ll> a(n);
    f(i,n){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        ll aa=0;
        f(i,n){
            if(((aa|a[i])&x)==(aa|a[i])){
                aa|=a[i];
            }
        }
        if(aa==x){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}