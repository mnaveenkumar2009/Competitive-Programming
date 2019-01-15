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
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
#define threshold 200
vl tree[400000];
ll n;
void build(){
    for(ll i=n-1;i>0;i--){
        set <ll> trr;
        for(auto it:tree[i<<1]){
            trr.insert(it);
        }
        for(auto it:tree[(i<<1)|1]){
            trr.insert(it);
        }
        for(auto it:trr){
            tree[i].pb(it);
        }
    }
    for(ll i=0;i<2*n;i++){
        set <ll> trr;
        for(auto it:tree[i]){
            trr.insert(it);
        }
        tree[i].erase(tree[i].begin(),tree[i].end());
        for(auto it:trr){
            tree[i].pb(it);
        }
    }
}
bool query(ll l,ll r,ll lq,ll rq){
    l+=n;
    r+=n;
    while(l<r){
        // cout<<l<<' '<<r<<' '<<"hv"<<'\n';
        if(l&1){
            if(*lower_bound(tree[l].begin(),tree[l].end(),lq)<=rq)
                return 1;
            l++;
        }
        if(r&1){
            r--;
            if(*lower_bound(tree[r].begin(),tree[r].end(),lq)<=rq)
                return 1;
        }
        l>>=1;
        r>>=1;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        n=sc;
        ll m=sc,i;
        f(i,2*n)
            tree[i].erase(tree[i].begin(),tree[i].end());
        vector <pair<ll,ll> > donga(m);
        f(i,m)
            donga[i]=mp(sc-1,sc-1);
        for(auto it:donga){
            tree[it.ff+n].pb(it.ss);
            tree[it.ss+n].pb(it.ff);
        }
        build();
        f(i,2*n)tree[i].pb(n+1);
        // f(i,2*n)prin(tree[i]);
        ll q=sc;
        while(q--){
            ll k=sc,i,j;
            vector <pair <ll,ll> > que(k);
            f(i,k){
                ll l=sc-1,r=sc-1;
                que[i]=mp(l,r);
            }
            if(k<=threshold){
                f(i,k)
                    for(j=i;j<k;j++)
                        if(query(que[i].ff,que[i].ss+1,que[j].ff,que[j].ss))
                            j=i=k+2;
                if(i==k)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else{
                vector <bool> querele(n);
                f(i,k)
                    for(ll j=que[i].ff;j<=que[i].ss;j++)
                        querele[j]=1;
                f(i,m)
                    if(querele[donga[i].ff]&&querele[donga[i].ss])
                      {i=m+10;}
                if(i==m)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
        }
    }
}