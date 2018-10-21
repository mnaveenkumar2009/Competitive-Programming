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
#define vvl vector <vector <ll> >
#define vl vector <ll>
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
    ll n=sc,m=sc;
    vvl a(n,vl (m));
    ll i,j,k;
    ll ans=0;


    // this times out .. remember to remove it and replace it with direct formula
    f(i,n){
        f(j,n){
            if(j>=i)
                ans+=((j-i+1)*m*(m+1))/2;
        }
    }
    
    f(i,n){
        f(j,m){
            a[i][j]=sc;
        }
    }
    f(j,m){
        unordered_map <ll,ll> xxx;
        f(i,n){
            if(xxx[a[i][j]])
                a[i][j]=(xxx[a[i][j]]);
            else{
                xxx[a[i][j]]=i+1;
                a[i][j]=i+1;
            }
        }
    }
    f(i,n){
        f(j,m)
            a[i][j]--;
    }
    // prin(a);
    vector <ll> xxx[m][n];
    f(j,m){
        f(i,n){
            xxx[j][a[i][j]].pb(i);
        }
        f(i,n){            
            xxx[j][i].pb(n+1);
        }
    }

    // f(j,m){
    //     f(i,n){
    //         prin(xxx[j][i]);
    //     }
    // }

    f(i,n){
        vector <ll> poss[n];
        f(j,m){
            ll pos=*upper_bound(xxx[j][a[i][j]].begin(),xxx[j][a[i][j]].end(),i);
            if(pos==n+1)continue;
            //leftmost conti with pos
            poss[pos].pb(j);
            ll low=0,high=poss[pos].size()-1;
            while(low!=high){
                ll mid=(low+high)/2;
                // if cont with mid
                bool we=0;
                if(j-poss[pos][mid]==poss[pos].size()-1-mid){
                    we=1;
                }
                if(we){
                    high=mid;
                }
                else{
                    low=mid+1;
                }
            }
            // cout<<pos<<' '<<low<<'\n';
            ll dista=j+1-poss[pos][low];
            ans-=(dista)*(i+1-0)*(n-pos);//ending at k
        }
    }
    
    cout<<ans;
    return 0;
}