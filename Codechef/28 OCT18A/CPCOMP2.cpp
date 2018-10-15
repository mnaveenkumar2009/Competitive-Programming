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
    f(i,a.size()/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,a.size()/2){
        cout<<a[a.size()/2+i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,n/2){
        cout<<a[n/2+i]<<' ';
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
vl numbers[threshold];
vvl alpath;
vl pathnum(threshold,-1);
vector <ll> adj[200008];
vector <bool> is(200008,0),vis(200008,0);
void dfs(ll node, vl &path){
    vis[node]=1;
    path.pb(node);
    ll i;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,path);
        }
    }
}
vl extra;
ll red(ll n){
    ll ans=1;
    for(ll i=2;(i<=threshold)&&(n!=1);i++){
        if(n%i==0){
            ans*=i;
            while(n%i==0)n/=i;
        }
    }
    // cout<<ans<<'\n';
    if(ans<threshold){
        is[ans]=1;
        numbers[ans].pb(n);
    }
    else{
        is[ans]=1;
        extra.pb(ans);
    }
    return ans;
}
// vl cnt(threshold,0);
int main()
{
    ll n=sc,i,j,k;
    f(i,threshold)f(j,threshold)adj[i][j]=0;

    // vector <ll> nums;
    f(i,n){
        red(sc);
        // nums.pb(red(sc));
        // cnt[nums[i]]++;
    }
    f(i,threshold){
        if(is[i]){
            f(j,threshold){
                if(i!=j){
                    if(is[j]&&__gcd(i,j)==1){
                        if(numbers[i].size()>1||numbers[j].size()>1){
                            adj[i].pb(j);
                            adj[j].pb(i);
                        }
                        if(numbers[i][0]!=numbers[j][0]){
                            adj[i].pb(j);
                            adj[j].pb(i);
                        }
                        if(numbers[i][0]==1){                            
                            adj[i].pb(j);
                            adj[j].pb(i);
                        }
                    }
                }
            }
        }
    }
    ll exsiz=extra.size();
    f(i,exsiz){
        f(j,exsiz){
            if(i!=j){
                if()
            }
        }
    }
    f(i,exsiz){
        ll numb=extra[i];
        f(j,threshold){
            if(is[j]){
                if(__gcd(j,numb)){
                    f(k,threshold){
                        if(is[k]){
                            if(i!=k){
                                if(__gcd(k,numb)){
                                    // adj[j][k]=1;
                                    // adj[k][j]=1;
                                    adj[k].pb(j);
                                    adj[j].pb(k);
                                    adj[k].pb(numb);
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    // f(i,10){
    //     f(j,10){
    //         cout<<adj[i][j]<<' ';
    //     }pc('\n');
    // }
    // f(i,n)cout<<nums[i]<<' ';pc('\n');
    f(i,threshold){
        if(is[i]){
            if(!vis[i]){
                vector <ll> path;
                dfs(i,path);
                for (auto it : path){
                    pathnum[it]=alpath.size();
                }
                alpath.pb(path);
            }
        }
    }
    ll ans=alpath.size();
    // for(auto v:alpath){
    //     for(auto it:v)
    //         cout<<it<<' ';
    //     pc('\n');
    // }
    // vector <bool> sep(n,0);
    // f(i,n){

    // }
    for (auto v:alpath){
        // v is path
        if(v.size()==1){
            ans+=numbers[v[0]].size()-1;
        }
        else{
            for (auto node:v){
                // 2 3 5
                for(auto curnum:numbers[node]){
                    if(curnum==1)continue;
                    bool we=1;
                    for(auto node2:v){
                        if(node!=node2){
                            if(numbers[node2][0]!=curnum||numbers[node2][numbers[node2].size()-1]!=curnum){
                                we=0;break;
                            }
                        }
                    }
                    if(we)ans++;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}