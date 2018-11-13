#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long

ll tree[200004]={0},n;

void build(){
    for(ll pos=n-1;pos>0;pos--){
        tree[pos]=tree[pos*2]^tree[pos*2+1];
    }
}

void modify(ll x, ll y){
    x+=n;
    tree[x]=y;
    while(x/=2){
        tree[x]=tree[x*2]^tree[x*2+1];
    }
}

ll query(ll l,ll r){
    // xor sum from l to r-1
    l+=n;
    r+=n;
    ll res=0;
    while(l<r){
        if(l&1){
            res^=tree[l++];
        }
        if(r&1){
            res^=tree[--r];
        }
        l/=2;
        r/=2;
    }
    return res;
}
int main(){
    
    ll q;
    cin>>n>>q;
    ll n1=(n+1)/2,n2=n/2;
    vector <ll> s(n,0),a(n),seven(n1,0),sodd(n2,0);

    ll i,j,k;
    f(i,n){
        cin>>a[i];
        ll upd=a[i];
        ll tem=min(i,n-i-1);
        if(tem%2){
            // modify(0,n1-1,upd);
            seven[0]^=upd;
            tem=(tem+1)/2;
            
            if(n1-tem<=n1-1)
                seven[n1-tem]^=upd;
            seven[tem]^=upd;

            // modify(tem,n1-tem-1,upd);
        }
        else{
            // modify(0,n1-1,upd);
            seven[0]^=upd;
            tem/=2;
            if(tem<=n2-tem-1){
                // modify2(tem,n2-tem-1,upd);
                if(n2-tem<=n2-1)
                    sodd[n2-tem]^=upd;
                sodd[tem]^=upd;
            }
        }
    }
    f(i,n1-1){
        seven[i+1]^=seven[i];
    }
    f(i,n2-1){
        sodd[i+1]^=sodd[i];
    }
    f(i,n){
        if(i&1)
            s[i]=sodd[i>>1];
        else
            s[i]=seven[i>>1];
    }
    f(i,n){
        s[n-i-1]=s[i];
    }

    f(i,n){
        tree[n+i]=s[i];
    }
    build();

    // f(i,2*n){
    //     cout<<tree[i]<<'\n';
    // }
    // f(i,n){
    //     cout<<query(i,i+1)<<'\n';
    // }
    while(q--){
        ll c;
        cin>>c;
        if(c==1){
            ll l,r;
            cin>>l>>r;
            cout<<query(l-1,r)<<'\n';
        }
        else{
            ll x,y;
            cin>>x>>y;
            modify(x-1,y);
        }
    }
}