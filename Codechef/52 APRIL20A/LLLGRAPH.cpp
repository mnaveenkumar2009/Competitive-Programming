// https://codeforces.com/blog/entry/49402
#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
const int M=2100;
struct struct_edge{int v;struct_edge* n;};
typedef struct_edge* edge;
struct_edge pool[M*M*2];
edge top=pool,adj[M];
int V,E,match[M],qh,qt,q[M],father[M],base[M];
bool inq[M],inb[M],ed[M][M];
void add_edge(int u,int v)
{
  top->v=v,top->n=adj[u],adj[u]=top++;
  top->v=u,top->n=adj[v],adj[v]=top++;
}
int LCA(int root,int u,int v)
{
  static bool inp[M];
  memset(inp,0,sizeof(inp));
  while(1)
    {
      inp[u=base[u]]=true;
      if (u==root) break;
      u=father[match[u]];
    }
  while(1)
    {
      if (inp[v=base[v]]) return v;
      else v=father[match[v]];
    }
}
void mark_blossom(int lca,int u)
{
  while (base[u]!=lca)
    {
      int v=match[u];
      inb[base[u]]=inb[base[v]]=true;
      u=father[v];
      if (base[u]!=lca) father[u]=v;
    }
}
void blossom_contraction(int s,int u,int v)
{
  int lca=LCA(s,u,v);
  memset(inb,0,sizeof(inb));
  mark_blossom(lca,u);
  mark_blossom(lca,v);
  if (base[u]!=lca)
    father[u]=v;
  if (base[v]!=lca)
    father[v]=u;
  for (int u=0;u<V;u++)
    if (inb[base[u]])
      {
	base[u]=lca;
	if (!inq[u])
	  inq[q[++qt]=u]=true;
      }
}
int find_augmenting_path(int s)
{
  memset(inq,0,sizeof(inq));
  memset(father,-1,sizeof(father));
  for (int i=0;i<V;i++) base[i]=i;
  inq[q[qh=qt=0]=s]=true;
  while (qh<=qt)
    {
      int u=q[qh++];
      for (edge e=adj[u];e;e=e->n)
        {
	  int v=e->v;
	  if (base[u]!=base[v]&&match[u]!=v)
	    if ((v==s)||(match[v]!=-1 && father[match[v]]!=-1))
	      blossom_contraction(s,u,v);
	    else if (father[v]==-1)
	      {
		father[v]=u;
		if (match[v]==-1)
		  return v;
		else if (!inq[match[v]])
		  inq[q[++qt]=match[v]]=true;
	      }
        }
    }
  return -1;
}
int augment_path(int s,int t)
{
  int u=t,v,w;
  while (u!=-1) 
    {
      v=father[u];
      w=match[v];
      match[v]=u;
      match[u]=v;
      u=w;
    }
  return t!=-1;
}
int edmonds(){
  int matchc=0;
  memset(match,-1,sizeof(match));
  for (int u=0;u<V;u++)
    if (match[u]==-1)
      matchc+=augment_path(u,find_augmenting_path(u));
  return matchc;
}


#define int long long
#define nll signed // not long long

vector <long long> VAL, NVAL;
vector <vector <pair <nll, nll> > > Adj;
vector <pair <nll, nll> > ED;
vector <bool> vis;
long long SIZ;
long long nc2(long long x){
    x *= x - 1;
    x /= 2;
    return x;
}
bool asdd = 0;
void dfs(int node, bool cur){
    vis[node] = 1;
    if(cur){
        SIZ = (SIZ + (NVAL[node]));
    }
    for(auto i:Adj[node]){
        if(!cur && (i.first > node)){
            if(asdd)
                SIZ = (SIZ + (VAL[i.second]));
            else
                SIZ = (SIZ + nc2(VAL[i.second]));
        }
        if(!vis[i.first])
            dfs(i.first,cur);
    }
}

signed main(){
    int u,v, K;
    cin >> V >> E >> K;
    ED.resize(E);
    Adj.resize(V);
    for(int i = 0; i < E; i++){
        cin>>u>>v;
        if(u > v)swap(u,v);
        ED[i] = {u-1, v-1};
        add_edge(u-1,v-1);
        ed[u-1][v-1]=ed[v-1][u-1]=true;
        Adj[u-1].push_back({v-1, i});
        Adj[v-1].push_back({u-1, i});
    }
    if(K==1){
        cout<<edmonds()<<endl;
        return 0;
    }
    bool modproblem = 0;
    
    while(K >= 7){
        vector <vector <pair <nll, nll> > > newAdj(E);
        int newE = 0;
        vector <pair <nll, nll> > newED;
        
        for(int i = 0; i < V; i++){
            for(auto n1:Adj[i]){
                for(auto n2:Adj[i]){
                    if(n1.second < n2.second){
                        int e1 = n1.second, e2 = n2.second;
                        newAdj[e1].push_back({e2, newE});
                        newAdj[e2].push_back({e1, newE});
                        newED.push_back({e1, e2});
                        newE++;
                    }
                }
            }
        }
        V = E;
        E = newE;
        Adj = newAdj;
        ED = newED;
        
        int EEE = 0;
        for(int i = 0; i < V; i++){
            EEE += nc2(Adj[i].size());
        }
        if(EEE > 1e9)modproblem = 1;

        K--;
    }
    //assert(!modproblem);
    VAL.resize(E);
    fill(VAL.begin(),VAL.end(), 1);
    NVAL.resize(V);
    
    vis.resize(V);
    fill(vis.begin(), vis.end(),0);
    for(int i = 0; i < V; i++)
        NVAL[i] = Adj[i].size();
    for(int i = 0; i < E; i++){
        VAL[i] = 0;
        if(NVAL[ED[i].second])
            VAL[i] += NVAL[ED[i].second] - 1;
        if(NVAL[ED[i].first]){
            VAL[i] += NVAL[ED[i].first] - 1;
        }
    }
    for(int i = 0; i < V; i++)
        NVAL[i] = nc2(Adj[i].size());
    if(K==2){
        for(int i = 0 ; i < E; i++)
            VAL[i] = 2;
    }
    if(K >= 5){
        int SUM[V], SIGASQ[V];
        for(int i = 0; i < V; i++){
            NVAL[i] = 0;
            int sum = 0, sigmaasq = 0, nn = Adj[i].size();
            for(auto j : Adj[i]){
                sum += VAL[j.second];
                sigmaasq += VAL[j.second] * VAL[j.second];
            }
            SUM[i] = sum;
            SIGASQ[i] = sigmaasq;
            NVAL[i] = (2*nn - 4)*sigmaasq - 10 * nn * sum + 2 * sum * sum + 6 * nn * nn - 6 * nn + 10 * sum;
            NVAL[i] /= 4;
        }
        
        if(K == 6){
            asdd = 1;
            
            for(int i = 0; i < E; i++){
                int u = ED[i].first, v = ED[i].second;
                int BEF = VAL[i], nu = Adj[u].size(), nv = Adj[v].size();
                VAL[i] = nc2(2 * BEF - 4) * (nc2(nu - 1) + nc2(nv - 1));
                // cout << VAL[i] << '\n';
                // cout << NVAL[u] << '\n';
                VAL[i] += NVAL[u] + (-BEF*BEF*(nu - 1) - (SIGASQ[u] - BEF*BEF) + 5 * (BEF * (nu - 1) + (SUM[u] - BEF)) - 6 * (nu - 1) - 2 * BEF * ((SUM[u] - BEF)))/2;
                // cout << VAL[i] << '\n';
                VAL[i] += NVAL[v] + (-BEF*BEF*(nv - 1) - (SIGASQ[v] - BEF*BEF) + 5 * (BEF * (nv - 1) + (SUM[v] - BEF)) - 6 * (nv - 1) - 2 * BEF * ((SUM[v] - BEF)))/2;
                
                // cout << VAL[i] << '\n';
                int sigmaaplusb = (nu - 2) * (SUM[u] - BEF) + (nv - 2) * (SUM[v] - BEF);
                // cout << sigmaaplusb << '\n';
                VAL[i] += (2 * BEF - 4) * ( sigmaaplusb - 2 * (nc2(nu - 1) + nc2(nv - 1)));
                int V2 = nc2(2*BEF - 6) * (nu - 1) * (nv - 1);
                V2 += (SUM[u] - BEF) * (SUM[v] - BEF) + (2*BEF - 6) * ((SUM[v] - BEF)*(nu - 1) + (SUM[u] - BEF) * (nv - 1));
                V2 += (((SIGASQ[u] - BEF * BEF) - (SUM[u] - BEF)) * (nv - 1) + ((SIGASQ[v] - BEF * BEF) - (SUM[v] - BEF)) *(nu - 1))/2;
                // cout << V2 << '\n';
                VAL[i] += V2;
                if(modproblem)
                    VAL[i] %= mod;
            }
            
        }
    }
    long long ans = 0;
    for(int i = 0; i < V; i++){
        SIZ = 0;
        if(!vis[i]){
            dfs(i, (K&1));
            ans = (ans + SIZ/2) % mod;
            if(modproblem){
                SIZ %= mod;
                ans = ((SIZ - 1) * (mod/2 + 1)) % mod;
            }
        }
    }
    cout << ans << '\n';
}
