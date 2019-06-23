#include <bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++)
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
unordered_map <ll,ll> xxx;
unordered_map <ll,bool> xxx2;
ll has(ll u,ll v){
    return (((u+v)*(u+v+1))/2) + min(u,v);
}

#define MAX 550
#define MAXE 500000
typedef pair<ll, ll> PII;
bool marked[MAX];
vector <PII> adj[MAX];
bool done[MAXE];
vector <PII> mst;
PII cable[MAXE];
char ans[MAX];
void prim(ll x){
    ans[x]='C';
    memset(marked,0,MAX);
    mst.clear();

    priority_queue< pair<PII,ll>,vector <pair<PII,ll> > > Q;
    ll y;
    pair<PII,ll> p;
    Q.push(mp(make_pair(0LL, x),-1LL));
    while(!Q.empty()){
        // Select the edge with max weight
        p = Q.top();
        Q.pop();
        x = p.first.second;
        
        if(marked[x] == true)
            continue;
        marked[x] = true;
        if(p.second!=-1){
            ans[x]='C'+'G'-ans[p.second];
            mst.pb(mp(x,p.second));
        }

        for(ll i = 0;i < adj[x].size();++i)
            if(marked[adj[x][i].second] == false){
                Q.push(mp(adj[x][i],x));
            }
    }
}
int main()
{
    ll x, y;
    ll n,m;
    cin>>n>>m;
    memset(done,0,MAXE);
    ll weight[m];
    ll s[n];
    f(i,n){
        cin>>s[i];
    }
    f(i,m)cin>>weight[i];
    for(ll i = 0;i < m;++i)
    {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(make_pair(weight[i], y));
        adj[y].push_back(make_pair(weight[i], x));
        xxx[has(x,y)]=i;
        cable[i]=mp(x,y);
    }
    prim(0);
    for(auto it:mst){
        // cout<<it.first<<" "<<it.second<<'\n';
        xxx2[has(it.first,it.second)]=1;
    }
    set< pair<ll,ll> > Q;
    f(i,m){
        if(!xxx2[has(cable[i].first,cable[i].second)]&&ans[cable[i].first]==ans[cable[i].second]){
            if((s[cable[i].first]*s[cable[i].second]) - weight[i]>0){
                Q.insert(mp(s[cable[i].first]*s[cable[i].second] - weight[i],i));
            }
        }
    }

    startofprint:

    while(Q.size()){
        auto itttt=Q.end();
        itttt--;
        pair <ll,ll> x=*itttt;
        if(s[cable[x.second].first]*s[cable[x.second].second]-weight[x.second]!=x.first){
            Q.erase(x);
            x.first=s[cable[x.second].first]*s[cable[x.second].second]-weight[x.second];
            Q.insert(x);
            continue;
        }
        cout<<x.second+1<<endl;
        done[x.second]=1;
        Q.erase(x);
        int c;
        cin>>c;
        if(c==1){
            int indexx,value;
            cin>>indexx>>value;
            indexx--;
            if(Q.find(mp(s[cable[indexx].first]*s[cable[indexx].second]-weight[indexx],indexx))!=Q.end()){
                Q.erase(mp(s[cable[indexx].first]*s[cable[indexx].second]-weight[indexx],indexx));
                weight[indexx]=value;
                if(s[cable[indexx].first]*s[cable[indexx].second]-weight[indexx]>0)
                    Q.insert(mp(s[cable[indexx].first]*s[cable[indexx].second]-weight[indexx],indexx));
            }
            weight[indexx]=value;
        }
        if(c==0){
            int indexx,value;
            cin>>indexx>>value;
            s[indexx-1]=value;
        }
    }
    xxx2.clear();
    prim(0);
    for(auto it:mst){
        xxx2[has(it.first,it.second)]=1;
    }
    Q.clear();
    f(i,m){
        if(!xxx2[has(cable[i].first,cable[i].second)]&&ans[cable[i].first]==ans[cable[i].second]&&!done[i]){
            if((s[cable[i].first]*s[cable[i].second]) - weight[i]>0){
                Q.insert(mp(s[cable[i].first]*s[cable[i].second] - weight[i],i));
            }
        }
    }
    if(Q.size()){
        goto startofprint;
    }
    f(i,n){
        for(auto &it:adj[i]){
            it.first=s[it.second]*s[i];
        }
    }
    prim(0);
    cout<<-1<<endl;
    for(int i=0;i<n;i++)cout<<ans[i];
    return 0;
}