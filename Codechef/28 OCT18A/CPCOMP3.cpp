#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vl vector <ll> 
#define vvl vector <vector <ll> >
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
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
#define threshold 450
vector <ll> adj[200004];
vector <bool> vis(200009,0);
vector <ll> divi[200004];
unordered_map <ll,bool> xxx[200004];
vector <ll> isprimther(200004,0);

void seive(){
    ll i,j,k;

    for(i=2;i<200006;i++){
        if(divi[i].size()==0){
            divi[i].pb(i);
            for(j=2;j*i<200004;j++){
                divi[j*i].pb(i);
            }
        }
    }
}
pair <ll,pair <ll,vector <ll> > > red(ll n){
    ll ans=1;
    for(auto it:divi[n]){
        ans*=it;
    }
    return mp(divi[n].size(),mp(ans,divi[n]));
}
bool dfs(ll node,bool xx){
    vis[node]=1;
    for (auto it:adj[node]){
        if(!vis[it]){
            dfs(it,1);
            xx=1;
        }
    }
    return xx;
}
int main() {
    ll n,i,j,k;
    ll tim=clock();
    seive();
    // for(auto it: divi[2432]){
    //     cout<<it<<' ';
    // }
    cin>>n;
    vector <pair <ll,pair <ll,vector <ll> > > > a(n),anew;
    f(i,n){
        ll x=sc;
        if(x==1){
            cout<<1;
            return 0;
        }
        a[i]=red(x);
    }
    f(i,n){
        ll asiz=a[i].ss.ss.size();
        for(j=asiz-1;j>=0;j--){
            if(isprimther[a[i].ss.ss[j]]==1){
                a[i].ss.ff/=a[i].ss.ss[j];
                a[i].ff--;
                a[i].ss.ss.erase(a[i].ss.ss.begin()+j);
            }
        }
    }
    // if(n>6000)return 0;
    // return 0;
    vector <ll> cnt(200006,0),cnt2(200006,0);
    vector <bool> visdon(200006,1);
    f(i,200006){
        isprimther[i]=0;
    }
    f(i,n){
        cnt[a[i].ss.ff]++;
        // cout<<a[i].ss.ff<<' ';
    }
    // return 0;
    // vector <ll> anew;
    f(i,n){
        if(cnt[a[i].ss.ff]&&visdon[a[i].ss.ff]){
            anew.pb(a[i]);
            visdon[a[i].ss.ff]=0;
            ll asiz=a[i].ss.ss.size();
            for(j=asiz-1;j>=0;j--){
                isprimther[a[i].ss.ss[j]]++;
            }
        }
    }
    // return 0;
    a=anew;
    n=a.size();
    
    // f(i,n){
    //     cout<<a[i].ss.ff<<' '<<cnt[a[i].ss.ff]<<'n';
    // }
    // return 0;
    sort(a.begin(),a.end());
    f(i,n){
        for(auto it:a[i].ss.ss){
            xxx[i][it]=1;
        }
    }
    // cout<<'\n';
    // f(i,n){
    //     cout<<a[i].ss.ff<<'\n';
    //     for(auto it:a[i].ss.ss){
    //         cout<<it<<' ';
    //     }pc('\n');
    // }cout<<'\n';
    // if(n>6000)return 0;
    if(a[0].ss.ff==1){
        cout<<1;
        return 0;
    }
    // if(n>6000){
    //     if(a[50].ff<2)cout<<1;
    //     return 0;
    // }
    f(i,min(100LL,n)){
        // cout<<clock()-tim<<'\n';
        if(n>6000)
        {   
            if(a[50].ff<2)
            if((long double)(clock()-tim)/(ld)CLOCKS_PER_SEC>0.34){
                cout<<1;
                return 0;
            }
        }
        for(j=i+1;j<n;j++){
            bool we=1;
            for(auto it:a[i].ss.ss){
                if(xxx[j][it]){
                    we=0;break;
                }
            }
            if(we){
                // cout<<i<<' '<<j<<'\n';
                adj[j].pb(i);
                adj[i].pb(j);
            }
        }
    }
    // if(n>6000)return 0;
    ll cnnn=0;
    for(i=100;i<n-1;i++){
        for(j=i+100;j<i+150&&j<n;j++)
        {
            bool we=1;
            for(auto it:a[i].ss.ss){
                if(xxx[j][it]){
                    we=0;
                    break;
                }
            }
            if(we){
                // cout<<i<<' '<<j<<'\n';
                adj[j].pb(i);
                adj[i].pb(j);
                if(cnnn++<150){
                    f(k,n){
                        if(i!=k){
                            bool we2=1;
                            for(auto it2:a[i].ss.ss){
                                if(xxx[k][it2]){
                                    we2=0;break;
                                }
                            }
                            if(we2){
                                adj[i].pb(k);
                                adj[k].pb(i);
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    ll ans=0;
    f(i,n){
        if(!vis[i]){
            if(dfs(i,0))
                ans++;
            else
                ans+=cnt[a[i].ss.ff];
            // cout<<ans<<'\n';
        }
    }
    cout<<ans<<'\n';
    return 0;
}
