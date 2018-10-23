#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll long long

int main()
{
    ll tt;
    cin>>tt;
    
    while(tt--){
        ll n;
        cin>>n;
        ll nc2=(n*(n-1))/2;
        ll a[nc2],b[nc2];

        ll l=log2(n);
        ll i,j,k;
        ll adj[500][500];
        f(i,500){
            f(j,500){
                adj[i][j]=0;
            }
        }
        f(i,nc2){
            cin>>a[i]>>b[i];
            adj[a[i]][b[i]]=1;
        }

        if((1LL<<l)!=n){
            cout<<"-1\n";
            continue;
        }

        vector <ll> rem;
        f(i,n)
            rem.pb(i+1);
        
        while(rem.size()>1){
            vector <ll> newrem;
            f(i,rem.size()/2){
                if(adj[rem[i*2]][rem[2*i+1]]==1){
                    newrem.pb(rem[2*i]);
                    adj[rem[i*2]][rem[2*i+1]]++;
                }
                else{
                    newrem.pb(rem[2*i+1]);
                    adj[rem[i*2+1]][rem[2*i]]++;
                }
            }
            rem=newrem;
        }

        cout<<nc2-(1<<l)+1<<'\n';
        f(i,nc2){
            if(adj[a[i]][b[i]]==1){
                cout<<i+1<<' ';
            }
        }
        cout<<'\n';

    }
    return 0;
}