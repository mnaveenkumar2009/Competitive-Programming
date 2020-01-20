#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000
#define M 1000
int a[N][M], R[N][M], S[N][M];
std::vector<int> adj[1000006], vis(1000006, 0);
int x;
void dfs(int node, int count, int& maxCount) { 
    vis[node] = true; 
    count++; 
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) { 
        if (!vis[*i]) { 
            if (count >= maxCount) { 
                maxCount = count; 
                x = *i; 
            }
            dfs(*i, count, maxCount); 
        } 
    } 
}
int root(int X){
    while(X != R[X/1000][X%1000])
        X = R[X/1000][X%1000];
    return X;
}
int diameter() { 
    int maxCount = 1; 
    for(int i = 0; i <= 1e6; i++){
        vis[i] = 0;
    }
    x = root(0);
    dfs(root(0), 1, maxCount);
    for(int i = 0; i <= 1e6; i++){
        vis[i] = 0; 
    }   
    dfs(x, 1, maxCount);
    return maxCount; 
} 
int siz(int X){
    X = root(X);
    return S[X/1000][X%1000];
}
void merge(int X, int Y){
    if(X==Y)
        return;
    X = root(X);
    Y = root(Y);
    int x1 = X/1000, y1 = X%1000;
    int x2 = Y/1000, y2 = Y%1000;
    if(siz(X) < siz(Y)){
        swap(X, Y);
        swap(x1, x2);
        swap(y1, y2);
    }
    S[x1][y1] += S[x2][y2];
    R[x2][y2] = X;
}
signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i <= 1e6; i++){
            adj[i].clear();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                R[i][j] = i*1000 + j;
                S[i][j] = 1;
                if(i-1>=0){
                    if(a[i-1][j] == a[i][j]){
                        merge((i-1)*1000 + j, i*1000 + j);
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1] == a[i][j]){
                        merge((i)*1000 + j, (i)*1000 + j-1);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i-1>=0){
                    if(a[i-1][j] != a[i][j]){
                        // cout << root(i*1000+j) << ' ' << root((i-1)*1000 + j) << '\n';
                        adj[root((i-1)*1000 + j)].push_back(root(i*1000 + j));
                        adj[root((i)*1000 + j)].push_back(root((i-1)*1000 + j));
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1] != a[i][j]){
                        // cout << root(i*1000+j) << ' ' << root((i)*1000 + j-1)<< '\n';
                        adj[root((i)*1000 + j-1)].push_back(root(i*1000 + j));
                        adj[root((i)*1000 + j)].push_back(root(i*1000 + j-1));
                    }
                }
            }
        }
        cout << (diameter())/2 << '\n';
    }
	return 0;
}