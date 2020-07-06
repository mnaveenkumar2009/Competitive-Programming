#include <bits/stdc++.h>
using namespace std;
 
#define N 1000
#define M 1000
int a[N][M], R[N][M], S[N][M];
int root(int X){
    while(X != R[X/1000][X%1000])
        X = R[X/1000][X%1000];
    return X;
}
int siz(int X){
    X = root(X);
    return S[X/1000][X%1000];
}
void merge(int X, int Y){
    X = root(X);
    Y = root(Y);
    if(X==Y)
        return;
    int x1 = X/1000, y1 = X%1000;
    int x2 = Y/1000, y2 = Y%1000;
    if(siz(X) < siz(Y)){
        swap(X, Y);
        swap(x1, x2);
        swap(y1, y2);
    }
    // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
    S[x1][y1] += S[x2][y2];
    R[x2][y2] = X;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        bool done[n][m];
        memset(done, 0, sizeof(done));
        vector <pair <int, pair <int, int> > > A;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                R[i][j] = i*1000 + j;
                S[i][j] = 1;
                int x;
                cin >> x;
                A.push_back({x, {i, j}});
            }
        }
        sort(A.begin(), A.end());
        int Ans[q];
        memset(Ans, 0, sizeof(Ans));
        A.push_back({1e9  + 5, {1, 2}});
        int cur = 0;
        vector <pair <pair <int, int>, pair <int, int> > > Q;
        for(int i = 0; i < q; i++){
            int r, c, p;
            cin >> r >> c >> p;
            Q.push_back({{p, i}, {r-1, c-1}});
        }
        sort(Q.begin(), Q.end());
        for(auto query : Q){
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < m; j++)
            //     cout << S[i][j] << ' ';
            //     cout << '\n';
            // }
            int ind = query.first.second;
            int p = query.first.first;
            int r = query.second.first;
            int c = query.second.second;
            while(A[cur].first < p){
                int i = A[cur].second.first, j = A[cur].second.second;
                // cout << ind << ' ' << i << ' ' << j << '\n';
                done[i][j] = 1;
                if(i - 1 >= 0){
                    if(done[i-1][j]){
                        merge(i * 1000 + j, (i-1) * 1000 + j);
                    }
                }
                if(i + 1 < n){
                    if(done[i+1][j]){
                        merge(i * 1000 + j, (i+1) * 1000 + j);
                    }
                }
                if(j - 1 >= 0){
                    if(done[i][j-1]){
                        merge(i * 1000 + j, (i) * 1000 + j - 1);
                    }
                }
                if(j + 1 < m){
                    if(done[i][j+1]){
                        merge(i * 1000 + j, (i) * 1000 + j + 1);
                    }
                }
                cur++;
            }
            if(done[r][c]){
                Ans[ind] =  siz(r * 1000 + c);
            }
        }
        for(int i = 0; i < q; i++)
            cout << Ans[i] << '\n';
    }

}