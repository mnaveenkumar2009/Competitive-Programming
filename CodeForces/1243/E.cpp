#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int, int> box;
signed main(){
    int k;
    cin >> k;
    vector < vector <int> > a(k);
    vector < vector <int> > cnt(k, vector<int> (k, -1));
    
    int siz[k], sum[k], tsum = 0;
    for(int i = 0; i < k; i++){
        sum[i] = 0;
        cin >> siz[i];
        a[i].resize(siz[i]);
        for(int j = 0; j < siz[i]; j++){
            cin >> a[i][j];
            tsum += a[i][j];
            sum[i] += a[i][j];
            box[a[i][j]] = i + 1;
        }
    }
    if(tsum % k){
        cout << "No\n";
        return 0;
    }
    tsum /= k;
    for(int i = 0; i < k; i++){
        for(int u = 0; u < siz[i]; u++){
            if(box[tsum - (sum[i] - a[i][u])]){
                cout << a[i][u] << box[tsum - (sum[i] - a[i][u])] << '\n';
                cnt[i][box[tsum - (sum[i] - a[i][u])] - 1] = a[i][u];
                cnt[box[tsum - (sum[i] - a[i][u])] - 1][i] = a[i][u];
            }
        }
    }
    vector <int> perm;
    for(int i = 0; i < k; i++){
        perm.push_back(i);
    }
    do{
        bool we = 1;
        for(int i = 0; i < k; i++){
            if(cnt[perm[i]][perm[(i+1)%k]] == -1){
                we = 0;
                break;
            }   
        }
        if(we){
            cout << "Yes\n";
            for(int i = 0; i < k; i++){
                cout << cnt[perm[i]][perm[(i+1)%k]] << ' ' << perm[(i+1)%k] + 1 << '\n';
            }
            return 0;
        }
    }
    while(next_permutation(perm.begin(), perm.end()));
    cout << "No\n";
}