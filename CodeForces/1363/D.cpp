#include <bits/stdc++.h>
using namespace std;
#define int long long

int coun;
int query(vector <int> v){
    coun++;
    // assert(coun < 12);
    cout << "? " << v.size() << ' ';
    for(auto i:v){
        cout << i << ' ';
    }cout << endl;
    int x;
    cin >> x;
    return x;
}
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    // int maxi = 0;
    // for(int i = 1; i <= 1000; i++){
    //     int x = i;
    //     int c = 0;
    //     while(x != 1){
    //         x = (x + 1) / 2;
    //         c++;
    //     }
    //     maxi = max(maxi, c);
    // }
    // cout << maxi << '\n';
    int t;
    cin >> t;
    while(t--){
        coun = 0;
        int n, k;
        cin >> n >> k;
        vector <int> S[k];
        for(int i = 0; i < k; i++){
            int X, x;
            cin >> X;
            for(int j = 0; j < X; j++){
                cin >> x;
                S[i].push_back(x);
            }
        }
        vector <int> D;
        for(int i = 0; i < k; i++){
            D.push_back(i);
        }
        vector <int> v;
        for(int i = 0; i < n; i++){
            v.push_back(i + 1);
        }
        int maxi = query(v);
        while(D.size() != 1){
            // for(auto i:D)cout << i << ' ';cout << '\n';
            v.clear();
            for(int i = 0; i < D.size()/2; i++){
                for(auto j:S[D[i]]){
                    v.push_back(j);
                }
            }
            if(query(v) == maxi){
                D.erase(D.begin() + D.size()/2, D.end());
            }
            else{
                D.erase(D.begin(), D.begin() + D.size()/2);
            }
        }
        int ans[k];
        for(int i = 0; i < k; i++){
            ans[i] = maxi;
        }
        v.clear();
        set <int> x;
        for(int i = 0; i < n; i++){
            x.insert(i + 1);
        }
        for(auto j:S[D[0]])x.erase(j);
        for(auto i:x)v.push_back(i);
        ans[D[0]] = query(v);
        cout << "! ";
        for(int i = 0; i < k; i++){
            cout << ans[i] << ' ';
        }cout << endl;
        string s;
        cin >> s;
    }
}