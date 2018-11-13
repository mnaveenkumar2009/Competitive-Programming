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
void prin(ll a[],ll n){
    ll i;
    f(i,n){
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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define vl vector <ll> 
#define vvl vector <vector <ll> >
void  xorr(vector <bool> &x1,vector <bool> &x2,vector <bool > &ans){
    ll n=x1.size(),i;
    f(i,n){
        ans[i]=x1[i]^x2[i];
    }
}
int main(){
    ll n=sc,i,j;
    vector <vector <bool > > xxx(n,vector <bool> (n,0));
    vl bas;
    f(i,n){
        ll k=sc;
        if(!k){
            xxx[i][i]=1;
        }
        f(j,k){
            xorr(xxx[i],xxx[sc-1],xxx[i]);
        }
    }   
    // f(i,n){
    //     f(j,n){
    //         cout<<xxx[i][j];
    //     }
    //     cout<<'\n';
    // }
    ll q=sc;
    while(q--){
        ll k=sc;
        vector <ll> inp(k);

        f(i,k){
            inp[i]=sc-1;
        }
        ll mask;
        f(mask,1<<k){
            if(!mask)continue;
            vector <bool>  xyz(n,0);
            f(j,k){
                if(mask&(1<<j)){
                    xorr(xyz,xxx[inp[j]],xyz);
                }
            }
            f(i,n){
                if(xyz[i])break;
            }
            if(i==n)break;
        }
        if(mask==1<<k){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
}