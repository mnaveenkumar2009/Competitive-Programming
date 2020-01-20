#include <bits/stdc++.h>
using namespace std;
#define int long long
int S[2000], R[2000], D[2000]; 
int root(int X){
    while(X != R[X])
        X = R[X];
    return X;
}
int siz(int X){
    X = root(X);
    return S[X];
}
void merge(int X, int Y){
    if(X==Y)
        return;
    X = root(X);
    Y = root(Y);
    if(siz(X) < siz(Y)){
        swap(X, Y);
    }
    S[X] += S[Y];
    R[Y] = X;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int x[n], y[n], k[n], c[n];
    for(int i = 0; i < n; i++){
        R[i] = i;
        S[i] = 1;
        D[i] = 0;
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    vector <pair <int, pair <int, pair <int, int> > > > X;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i==j){
                X.push_back({c[i], {1, {i, i}}});
            }
            else{
                int temp = (abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i]+k[j]);
                X.push_back({temp, {2, {i, j}}});
            }
        }   
    }
    sort(X.begin(), X.end());
    std::vector<int> shrine;
    std::vector<pair <int, int> > pipes;
    int ans = 0;
    for(auto T:X){
        int typ = T.second.first;
        if(typ == 1){
            int x = T.second.second.first;
            if(!D[root(x)]){
                // cout << x << '\n';
                shrine.push_back(x+1);
                D[root(x)] = 1;
                ans += T.first;
            }
        }
        else{
            int x = T.second.second.first, y = T.second.second.second;
            if(root(x) != root(y)){
                bool we = D[root(x)] || D[root(y)];
                if(!D[root(x)] || !D[root(y)]){   
                    // cout << x << ' ' << y << '\n';
                    pipes.push_back({x+1, y+1});
                    ans += T.first;
                    merge(x, y);
                    D[root(x)] = we;
                }
            }
        }
    }
    cout << ans << '\n';
    cout << shrine.size() << '\n';
    for(auto i:shrine){
        cout << i << ' ';
    }
    cout << '\n';
    cout << pipes.size() << '\n';
    for(auto i:pipes){
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}