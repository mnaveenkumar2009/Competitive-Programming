#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        s.pb('A');
        vector <pair <ll,ll> > dp[26][26];
        ll i,j,k,coun=0;
        vector <pair <ll,ll> > a;
        f(i,n){
            coun++;
            if(s[i]!=s[i+1]){
                a.pb(mp(coun,s[i]-'a'));
                coun=0;
            }
        }
        n=a.size();
        f(i,n-1){
            dp[a[i].ss][a[i+1].ss].pb(mp(a[i].ff,a[i+1].ff));
        }
        
    }
}