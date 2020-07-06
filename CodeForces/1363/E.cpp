#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> adj[200003];
int B[200003], A[200003];

void dfs(int node, int par, int val){
    A[node] = min(A[node], val);
    for(auto child : adj[node]){
        if(child != par)
            dfs(child, node, A[node]);
    }
}
pair <pair <int, int>, int> dfs(int node, int par){
    pair <pair <int, int>, int> X = {{0, 0}, 0};
    if(B[node] != -1){
        if(B[node] == 0)
            X.first.first++;
        else
            X.first.second++;
    }
    for(auto child : adj[node]){
        if(child != par){
            pair <pair <int, int>, int> Y = dfs(child, node);
            X.first.first += Y.first.first;
            X.first.second += Y.first.second;
            X.second += Y.second;
        }
    }
    int mini = min(X.first.first, X.first.second);
    X.second += mini * 2 * A[node];
    X.first.first -= mini;
    X.first.second -= mini;
    if(node == 0 && (X.first.first || X.first.second)){
        X.second = -1;
    }
    // cout << node << ' ' << X.first.first << ' ' << X.first.second << ' ' << X.second << '\n';
    return X;
}
signed main(){
    int n, x, y, z, u, v;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i] >> y >> z;
        if(y == z){
            B[i] = -1;
        }
        else{
            B[i] = y;
        }
    }
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u-1].push_back(v - 1);
        adj[v-1].push_back(u - 1);
    }
    dfs(0, -1, 1e18);
    cout << dfs(0, -1).second << '\n';

}