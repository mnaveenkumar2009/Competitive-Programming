#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define threshold 450
vector <ll> adj[200004];
vector <bool> vis(200009,0);
vector <ll> divi[200004];
unordered_map <ll,bool> xxx[5004];
ll red(ll n,ll pos){
    ll ans=1;
    for(ll i=2;(i<=threshold)&&(n!=1);i++){
        if(n%i==0){
            divi[pos].pb(i);
            xxx[pos][i]=1;
            while(n%i==0)n/=i;
        }
    }
    if(n!=1){
        divi[pos].pb(n);
        xxx[pos][n]=1;
    }
    return ans;
}
void dfs(ll node){
    vis[node]=1;
    for (auto it:adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
int main() {
    ll n,i,j,k;
    cin>>n;
    vector <ll> a(n);
    f(i,n){
        cin>>a[i];
        red(a[i],i);
    }
    f(i,n){
        f(j,n){
            if(i<j){
                bool we=1;
                for(auto it:divi[i]){
                    if(xxx[j][it]){
                        we=0;break;
                    }
                }
                if(we){
                    adj[j].pb(i);
                    adj[i].pb(j);
                }
            }
        }
    }
    ll ans=0;
    f(i,n){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
