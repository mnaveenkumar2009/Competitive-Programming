#include <bits/stdc++.h>
using namespace std;
vector <bool> vis(1e6, 0);
vector <int> treesiz(1e6, 0);
vector <int> id, par(1e6, -1), adj[100006];
bool f(int i, int j){
    return treesiz[i] < treesiz[j];
}
int dfs2(int node){
    vis[node] = 1;
    treesiz[node] = 1;
    for(auto child:adj[node]){
        if(!vis[child]){
            treesiz[node]  += dfs2(child);
        }
    }
    return treesiz[node];
}
void dfs(int node){
    // vis[node] = 1;
    // id.push_back(node);
    // for(auto child:adj[node]){
    //     if(!vis[child]){
    //         dfs(child);
    //     }
    // }
    list<int> queue; 
    queue.push_back(node); 
    vis[node] = 1;
    vector<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        node = queue.front(); 
        id.push_back(node);
        queue.pop_front();
        for (i = adj[node].begin(); i != adj[node].end(); ++i) 
        { 
            if (!vis[*i]) 
            { 
                vis[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        par[i] = x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs2(0);
    for(int i = 0; i < n; i++)vis[i] = 0;
    // for(int i = 0; i < n; i++)cout << treesiz[i] << ' ';cout << '\n';
    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end(), f);
    dfs(0);
    unordered_map <int ,int > prev;
    prev[0] = -1;
    int adjsiz[n];
    for(int i = 0; i < n; i++){
        cout << id[i] << ' ';
        if(i)
            prev[id[i]] = id[i-1];
        adjsiz[id[i]] = adj[id[i]].size() - 1;
    }
    cout << '\n';
    adjsiz[0] = 1e7;
    vector <int> ans;
    for(int i = 1; i < n; i++){
        if(adjsiz[prev[id[i]]] == 0){
            ans.push_back(id[i]);
        }
    }
    vector <int> prin;
    while(ans.size()){
        vector <int> nans;
        for(auto i:ans){
            prin.push_back(i); 
            prev[i] = prev[prev[i]];
            if(prev[i]!=-1){
                adjsiz[prev[i]]--;
                if(adjsiz[prev[i]] == 0){
                    nans.push_back(i);
                }
            }
        }
        ans = nans;
    }
    cout<<prin.size() << '\n';
    for(auto i:prin){
        cout << i << ' ';
    }
    cout << '\n';
}