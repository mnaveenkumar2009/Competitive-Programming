#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 52
#define M 52
int a[N][M], R[N][M], S[N][M];
vector<int> adj[52006];
bool vis[3000];
void bfs(int u, int& maxCount) {
    list<pair <int, int> > queue;
    vis[u] = true;
    queue.push_back({u, 1});
    while(!queue.empty()) 
    {
        auto s = queue.front();
        maxCount = max(maxCount, s.second);
        queue.pop_front();
        for (auto i = adj[s.first].begin(); i != adj[s.first].end(); ++i)
        { 
            if (!vis[*i]){
                vis[*i] = true;
                queue.push_back({*i, s.second+1});
            } 
        } 
    } 
}
int root(int X){
    while(X != R[X/52][X%52])
        X = R[X/52][X%52];
    return X;
}
int diameter(int n, int m) {
    int ret = 1e9;
    for(int ii = 0; ii < n; ii ++)
        for(int jj = 0; jj < m; jj++){
            int maxCount = 0;
            memset(vis, 0, sizeof(vis));
            bfs(root(ii*52 + jj), maxCount);
            ret = min(ret, maxCount);
        }
    return ret-1; 
} 
int siz(int X){
    X = root(X);
    return S[X/52][X%52];
}
void merge(int X, int Y){
    if(X==Y)
        return;
    X = root(X);
    Y = root(Y);
    int x1 = X/52, y1 = X%52;
    int x2 = Y/52, y2 = Y%52;
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
        for(int i = 0; i <= 5200; i++){
            adj[i].clear();
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                R[i][j] = i*52 + j;
                S[i][j] = 1;
                if(i-1>=0){
                    if(a[i-1][j] == a[i][j]){
                        merge((i-1)*52 + j, i*52 + j);
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1] == a[i][j]){
                        merge((i)*52 + j, (i)*52 + j-1);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i-1>=0){
                    if(a[i-1][j] != a[i][j]){
                        adj[root((i-1)*52 + j)].push_back(root(i*52 + j));
                        adj[root((i)*52 + j)].push_back(root((i-1)*52 + j));
                    }
                }
                if(j-1>=0){
                    if(a[i][j-1] != a[i][j]){
                        adj[root((i)*52 + j-1)].push_back(root(i*52 + j));
                        adj[root((i)*52 + j)].push_back(root(i*52 + j-1));
                    }
                }
            }
        }
        cout << (diameter(n, m)) << '\n';
    }
	return 0;
}