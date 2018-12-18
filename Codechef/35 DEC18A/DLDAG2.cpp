#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
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

set <int> ado[1000006],adi[1000005];
vl coun(1000006,-1),ocoun,par(1000006,0),parbuf(1000006,0);
ll f2(ll node){
    if(coun[node]!=-1)return coun[node];
    coun[node]=1;
    for(auto it:ado[node]){
        coun[node]+=f2(it);
    }
    return coun[node];
}

long long has(ll x,ll y){
    long long sum=(x+y);
    sum*=sum+1;
    sum>>=1;
    return sum+min(x,y);
}
int main()
{
    ll n=sc,m=sc,i;
    unordered_map<long long,bool> xxx;
    while(m--){
        ll x=sc-1,y=sc-1;
        ado[x].insert(y);
        adi[y].insert(x);
        xxx[has(x,y)]=1;
    }
    f(i,n){
        coun[i]=f2(i);
        // ocoun[i]=coun[i];
    }
    ocoun=coun;
    f(i,n){
        for(auto it:adi[i]){
            par[i]+=coun[it];
        }
        // cout<<par[i]<<' ';
    }
    // par - coun*adi[itt].size()
    ll finans=INT_MAX;
    vector <ll> finprin;
    ll numberoftime=2;
    while(numberoftime--){
        vector <pair <ll,ll> > deleted;
        set <pair <ll,ll> > ans;
        vector <ll> prin;
        ll ccc=0,i;
        f(i,n){
            if(!ado[i].size())
                if(numberoftime)
                ans.insert(mp(par[i] - coun[i]*adi[i].size(),i));
                else
                ans.insert(mp(coun[i]*adi[i].size()-par[i],i));

        }
        
        while(ans.size()){
            
            set <pair <ll,ll> > ::iterator it,it2;
            it=ans.begin();
            it2=it;
            it2++;
            if(ans.size()==1){
                // cout<<"1 "<<(*it).ss+1<<'\n';
                pair <ll,ll> xyz=*it;
                ccc++;
                // prin.pb(1);
                prin.pb((*it).ss+1);
                for(auto itt:adi[(*it).ss]){
                    ado[itt].erase((*it).ss);
                    // for(auto nod:adi[(*it).ss]){
                        coun[itt]-=ocoun[(*it).ss];
                    // }coun[(*it).ss]=0;
                    deleted.pb(mp(itt,(*it).ss));
                }
                for(auto itt:adi[(*it).ss]){
                    if(!ado[itt].size()){
                        par[itt]=0;
                        for(auto nod:adi[itt]){
                            par[itt]+=coun[nod];
                        }
                        if(numberoftime)
                        ans.insert(mp(par[itt] - coun[itt]*adi[itt].size(),itt));
                        else
                        ans.insert(mp(coun[itt]*adi[itt].size()-par[itt] ,itt));

                    }
                }
                ans.erase(xyz);
            }
            else{
                pair <ll,ll> xyz=*it;
                pair <ll,ll> xyz2=*it2;
                ccc++;
                // prin.pb(2);
                prin.pb((*it).ss+1);
                prin.pb((*it2).ss+1);
                for(auto itt:adi[(*it).ss]){
                    ado[itt].erase((*it).ss);
                    // for(auto nod:adi[(*it).ss]){
                        coun[itt]-=ocoun[(*it).ss];
                    // }coun[(*it).ss]=0;
                    deleted.pb(mp(itt,(*it).ss));
                }
                for(auto itt:adi[(*it).ss]){
                    if(!ado[itt].size()){
                        par[itt]=0;
                        for(auto nod:adi[itt]){
                            par[itt]+=coun[nod];
                        }
                        if(numberoftime)
                        ans.insert(mp(par[itt] - coun[itt]*adi[itt].size(),itt));
                        else
                        ans.insert(mp(coun[itt]*adi[itt].size()-par[itt] ,itt));
                    }
                }
                it=it2;
                for(auto itt:adi[(*it).ss]){
                    ado[itt].erase((*it).ss);
                    // for(auto nod:adi[(*it).ss]){
                        coun[itt]-=ocoun[(*it).ss];
                    // }coun[(*it).ss]=0;
                    deleted.pb(mp(itt,(*it).ss));
                    if(!ado[itt].size()){
                        par[itt]=0;
                        for(auto nod:adi[itt]){
                            par[itt]+=coun[nod];
                        }
                        if(numberoftime)
                        ans.insert(mp(par[itt] - coun[itt]*adi[itt].size(),itt));
                        else
                        ans.insert(mp(coun[itt]*adi[itt].size()-par[itt] ,itt));
                    }
                }
                ans.erase(xyz);
                ans.erase(xyz2);
            }
        }
        for(auto it:deleted){
            ado[it.ff].insert(it.ss);
        }
        if(ccc<finans){
            finans=ccc;
            finprin=prin;
        }
    }
    vector <ll> stak=finprin;
    finans=0;
    finprin.erase(finprin.begin(),finprin.end());
        int ffff=3;
        while(ffff--)
        for(int i=n-1;i>=2;i--){
            if(xxx[has(stak[i]-1,stak[i-1]-1)]){
                if(!xxx[has(stak[i-1]-1,stak[i-2]-1)]){
                    swap(stak[i-1],stak[i-2]);
                }
            }
        }
        ffff=3;
        while(ffff--)
        for(int i=0;i<n-2;i++){
            if(xxx[has(stak[i]-1,stak[i+1]-1)]){
                if(!xxx[has(stak[i+1]-1,stak[i+2]-1)]){
                    swap(stak[i+1],stak[i+2]);
                }
            }
        }

        for(int i=0;i<n;i++){
            // cout<<stak[i]<<' ';
            // cout<<i<<'\n';
            bool we=0;
            if(i!=n-1){
                if(!xxx[has(stak[i]-1,stak[i+1]-1)]){
                    we=1;
                }
            }
            if(we){
                finans++;
                finprin.pb(2);
                finprin.pb(stak[i]);
                finprin.pb(stak[++i]);
            }
            else{
                finans++;
                finprin.pb(1);
                finprin.pb(stak[i]);
            }
        }
    cout<<finans;
    ll xxxx=0;
    for(auto it:finprin){
        if(!xxxx){
            cout<<'\n';
            xxxx+=it+1;
        }
        cout<<it<<' ';
        xxxx--;
    }
	return 0;
}