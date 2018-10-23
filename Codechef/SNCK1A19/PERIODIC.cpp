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

int main()
{
    ll t=sc;
    while(t--){
        ll n=sc,i,j,k;
        vl a(n);
        bool we=1;
        ll maxi=-1;
        f(i,n){
            a[i]=sc;
            maxi=max(a[i],maxi);
            if(i){
                if(a[i]!=1){
                    if(a[i-1]!=a[i]-1)we=0;
                }
            }
        }
        if(maxi==-1){
            cout<<"inf\n";
            continue;
        }
        f(i,n-1){
            ll ind=n-i-1;
            if(a[ind]>1){
                a[ind-1]=a[ind]-1;
            }
        }
        f(i,n-1){
            if(a[i]<maxi){
                a[i+1]=a[i]+1;
            }
        }
        prin(a);
        vector<ll> xxx[105];
        f(i,n){
            if(a[i]!=-1)
                xxx[a[i]].pb(i);
        }
        prin(a);
        f(i,1e6){
            cout<<xxx[i].size()<<'\n';
            f(j,xxx[i].size()-1){
                cout<<"f";
                maxi=min(maxi,1+xxx[i][j+1]-xxx[i][j]);
            }
        }
        maxi=INT_MAX;
        f(i,n-1){
            if(a[i]!=-1){
                a[i+1]=((a[i]+1)%maxi)+1;
            }
        }
        prin(a);
        if(!we){
            cout<<"impossible\n";
        }
        else{
            if(maxi==INT_MAX){
                cout<<"inf\n";
            }
            else
                cout<<maxi<<'\n';
        }
        // 2 3 4 5 1 2 3 4 5 2 
    }
    return 0;
}