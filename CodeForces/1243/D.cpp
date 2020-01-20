
#include<bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/920/problem/E
#define maxn 100005
set<int> st;
vector<int> g[maxn];
int n,m,cnt,num[maxn],vis[maxn],nxt[maxn],pre[maxn];;
void erase(int p) {
  nxt[pre[p]]=nxt[p];
  pre[nxt[p]]=pre[p];
}
void work(int p) {
  queue<int> Q;Q.push(p);
  while(!Q.empty())
  {
    int x=Q.front();Q.pop();
    for(int i=0;i<g[x].size();i++)
    {
      int v=g[x][i];
      vis[v]=1;
    }
    for(int i=nxt[0];i<=n;i=nxt[i])
      if(!vis[i])
      {
        erase(i);num[cnt]++;Q.push(i);
      }
    for(int i=0;i<g[x].size();i++)
    {
      int v=g[x][i];
      vis[v]=0;
    }
  }
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<=n;i++) nxt[i]=i+1;
    for(int i=1;i<=n+1;i++) pre[i]=i-1;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = nxt[0]; i <= n; i = nxt[0]){
        erase(i);
        num[++cnt] = 1;
        work(i);
    }
    cout << cnt - 1 << '\n';
    return 0;
}