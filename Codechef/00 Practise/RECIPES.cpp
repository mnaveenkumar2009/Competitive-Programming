#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
#define vvl vector <vector<ll> > 
#define vl vector <ll>
set <ll> bases;
ll ran(){
    while(1){
        ll x=((ll)rand()*(ll)rand());
        // x|=(1LL<<63);
        if(bases.find(x)==bases.end()){
            bases.insert(x);
            return x;
        }
    }
    return 1;
}
void xorr(vvl &mat,ll row1,ll row2){
    for(ll i=0;i<64;i++){
        mat[row1][i]^=mat[row2][i];
    }
}
ll k;
void guas(vvl &mat){
    ll i,j;
    ll curj=0;
    f(j,k){
        if(mat[j][curj]==0){
            for(ll i=j+1;i<k;i++){
                if(mat[i][curj]){
                    swap(mat[j],mat[i]);
                    break;
                }
            }
        }
        if(mat[j][curj]==0){
            curj++;
            j--;
            if(curj==64)
                break;
            continue;
        }
        for(i=j+1;i<k;i++){
            if(mat[i][curj]){
                xorr(mat,i,j);
            }
        }
        curj++;
    }
}
int main(){
    ll N;
    cin>>N;
    ll P[N];
    vector <ll> XXX[N];


    for(int i=0;i<N;i++){
        cin>>P[i];
        XXX[i].resize(P[i]);
        for(int j=0;j<P[i];j++){
            cin>>XXX[i][j];
        }
    }

    ll Q;
    cin>>Q;
    ll K[Q];
    vector <ll> X[Q];
    for(int i=0;i<Q;i++){
        cin>>K[i];
        X[i].resize(K[i]);
        for(int j=0;j<K[i];j++){
            ll x;
            cin>>x;
            X[i][j]=x;
        }
    }
    // cout<<Q<<'\n';
    string ans;
    for(int ii=0;ii<Q;ii++){
        ans.push_back('1');
    }
    ll noc=2;
    while(noc--)
    {
        bases.erase(bases.begin(),bases.end());
        ll n=N;
        ll p[n];
        ll comb[n]={0};
        for(int i=0;i<n;i++){
            p[i]=P[i];
            if(!p[i]){
                comb[i]=ran();
            }
            else{
                for(int j=0;j<p[i];j++){
                    ll xxx=XXX[i][j];
                    comb[i]^=comb[xxx-1];
                }
            }
            // cout<<comb[i]<<'\n';
        }
        // cout<<'\n';
        // for(auto it:bases)cout<<it<<'\n';cout<<'\n';
        ll q=Q;
        ll xyz;
        f(xyz,q){
            k=K[xyz];
            vvl mat(k, vl(64,0));
            for (ll i=0;i<k;i++){
                ll x=X[xyz][i];
                x--;
                x=comb[x];
                // if(xyz==1)cout<<x<<'\n';
                for(ll j=0;j<64;j++){
                    if(x&(1LL<<j)){
                        mat[i][j]=1;
                    }
                    else{
                        mat[i][j]=0;
                    }
                }
            }
            // if(xyz==1)cout<<'\n';
            // if(xyz==1){
            //     ll i,j;
            //     f(i,k){
            //         f(j,64){
            //             cout<<mat[i][j];
            //         }cout<<'\n';
            //     }
            //     cout<<'\n';
            // }
            guas(mat);
            // if(xyz==1){
            //     ll i,j;
            //     f(i,k){
            //         f(j,64){
            //             cout<<mat[i][j];
            //         }cout<<'\n';
            //     }
            //     cout<<'\n';
            // }
            bool we=1;
            ll kkk;
            f(kkk,k){
                we=1;
                for(ll i=0;i<64;i++){
                    if(mat[kkk][i])we=0;
                }
                if(we)break;
            }
            if(!we){
                // cout<<xyz<<'\n';
                ans[xyz]='0';
            }
        }
    }
    cout<<ans<<'\n';
}