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

vector <vector <ll> > mul(vector <vector <ll> > &a,vector <vector <ll> > &b){
    vector <vector <ll> > res(3,vector<ll> (3));
    int i, j, k; 
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] = (res[i][j]+(a[i][k]*b[k][j])%mod)%mod;
        }
    }

    return res;
}

int main()
{
    ll q=sc;
    vector < vector <ll> > mat(3,vector <ll> (3,0)),id(3,vector<ll> (3,0));
    id[0][0]=1;
    id[1][1]=1;
    id[2][2]=1;
    mat[0][0]=2;
    mat[0][1]=2;
    mat[0][2]=2;
    mat[1][0]=1;
    mat[1][1]=2;
    mat[2][2]=1;

    vector < vector <ll> > exmat[80];
    exmat[0]=mat;
    for(ll i=1;i<80;i++){
        exmat[i]=mul(exmat[i-1],exmat[i-1]);
    }
    while(q--){
        ll n=sc;
        if(n==0){
            cout<<"2\n";
            continue;
        }
        if(n&1){
            vector <vector <ll> > res=id;
            ll x=(n-1)/2;
            for(ll j=0;j<42;j++){
                if((1LL<<j)&x){
                    res=mul(res,exmat[j]);
                }
            }
            ll ans=(res[1][0]*7+res[1][1]*3 + res[1][2])%mod;
            cout<<ans<<'\n';
        }
        else{
            //even
            vector <vector <ll> > res=id;
            ll x=(n-2)/2;
            for(ll j=0;j<42;j++){
                if((1LL<<j)&x){
                    res=mul(res,exmat[j]);
                }
            }
            ll ans=(res[0][0]*7+res[0][1]*3 + res[0][2])%mod;
            cout<<ans<<'\n';
        }
    }
    return 0;
}