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
bool we=1;
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}

#define sc uscan()

#define revsort1(a) sort(a.begin(),a.end(),greater <int>())

int main() {
    string s;
    cin>>s;
    ll i,j,k,n=s.length();
    vector <ll> a;
    ll c=0;
    f(i,n){
        if(s[i]==')'){
            c++;
        }
        else{
            if(c)
                a.pb(c);
            c=0;
        }
    }
    a.pb(c);
    n=a.size();
    vl aold=a;
    // vl con[100005];
    
    if(a.size()==1){
        cout<<a[0]<<'\n';
    }
    else{
        n=a.size();
        revsort1(a);
        // prin(a);
        vl cou(1000005,0);
        f(i,n){
            cou[a[i]]++;
        }
        ll a1=a[0],a2=a[1];
        // cout<<a1<<' '<<a2<<'\n';
        if(a2==0){
            cout<<a[0]<<'\n';
            return 0;
        }
        ll cons=0;
        vl con[2];
        f(i,n-1){
            if(aold[i]!=a1){
                cons=0;
                continue;
            }
            if(aold[i+1]==aold[i]){
                cons++;
            }
            else{
                con[0].pb(cons+1);
                cons=0;
            }
        }
        if(aold[n-1]==a1){
            con[0].pb(cons+1);
        }
        cons=0;
        f(i,n-1){
            if(aold[i]!=a2){
                cons=0;
                continue;
            }
            if(aold[i+1]==aold[i]){
                cons++;
            }
            else{
                // if(cons)
                con[1].pb(cons+1);
                cons=0;
            }
        }
        if(aold[n-1]==a2){
            con[1].pb(cons+1);
        }
        // prin(con[0]);//a1
        // prin(con[1]);//a2

        if(a1==a2){
            ll ans=0;
            cout<<(cou[a1]*(cou[a2]-1))<<'\n';
            // for(auto it:con[0]){
            //     (it*)
            // }
            // cout<<ans<<'\n';
        }
        else{
            // cout<<2*cou[a1]*cou[a2]<<'\n';
            ll ans=0;
            for(auto it:con[0]){
                ans+=((it*(it+1))/2)*(cou[a2]);
            }
            for(auto it:con[1]){
                ans+=((it*(it+1))/2)*(cou[a1]);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
