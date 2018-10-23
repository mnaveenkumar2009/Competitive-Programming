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

int main(){
    ll t=sc;
    while(t--){
        ll n=sc,K=sc;
        string a,b;
        cin>>a>>b;
        ll i,j,k;
        ll ans=0;
        f(i,n){
            ll l1=0;
            ll l2=i;
            string s1=a.substr(0,n-i),s2=b.substr(i,n-i);
            ll siz=n-i;
            
            ll cur=0;
            k=-1;
            // cout<<s1<<' '<<s2<<'\n';
            f(j,siz){
                k=max(k,j-1);
                // cout<<"ola";
                while(k!=siz-1){
                    if(cur+(s1[k+1]!=s2[k+1])<=K){
                        cur+=(s1[k+1]!=s2[k+1]);
                        k++;
                    }
                    else{
                        break;
                    }
                }
                // cout<<i<<' '<<j<<' '<<k<<'\n';
                ans+=k+1-j;
                if(k>=j){
                    cur-=s1[j]!=s2[j];
                }
                // cout<<ans<<'\n';
            }
        }
        // return 0;
        f(i,n-1){
            // ll l1=i,l2=0;
            string s1=b.substr(0,n-(i+1)),s2=a.substr(i+1,n-(i+1));
            ll siz=n-(i+1);
            
            ll cur=0;
            k=-1;
            // cout<<s1<<' '<<s2<<'\n';
            f(j,siz){
                k=max(k,j-1);
                // cout<<"ola";
                while(k!=siz-1){
                    if(cur+(s1[k+1]!=s2[k+1])<=K){
                        cur+=(s1[k+1]!=s2[k+1]);
                        k++;
                    }
                    else{
                        break;
                    }
                }
                // cout<<i<<' '<<j<<' '<<k<<'\n';
                ans+=k+1-j;
                if(k>=j){
                    cur-=s1[j]!=s2[j];
                }
                // cout<<ans<<'\n';
            }
        }
        cout<<ans<<'\n';

    }
}