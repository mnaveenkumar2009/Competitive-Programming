#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 1e9;
    cin >> n;
    pair <int, int> X[n];
    for(int i = 0; i < n; i++){
        cin >> X[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> X[i].second;
    }
    for(int mask = 0; mask < (1 << n); mask ++){
        pair <int, int> S[n];
        for(int i = 0; i < n; i++){
            if(mask & (1LL<<i))
                S[i] = {X[i].second, i};
            else
                S[i] = {X[i].first, i};
        }
        int cur_ans = 0;
        sort(S, S + n);
        bool we = 1;

        for(int i = 0; i < n; i++){
            int mini = (*min_element(S + i, S + n)).first;
            int pos = 1e9, swap_ind = 1e9;
            for(int j = i; j < n; j++){
                if(S[j].first == mini){
                    if((abs(S[j].second - i) % 2) == ((mask >> S[j].second) & 1)){
                        if(S[j].second < pos){
                            pos = S[j].second;
                            swap_ind = j;
                        }
                    }
                }
            }
            if(pos != 1e9){
                swap(S[swap_ind], S[i]);
            }
            else{
                we = 0;
                break;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(S[i].second > S[j].second){
                    cur_ans++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if((abs(S[i].second - i) % 2) != ((mask >> S[i].second) & 1))
                we = 0;
        }
        if(we && ans > cur_ans){
            ans = cur_ans;
        }
    }
    if(ans == 1e9)
        ans = -1;
    cout << ans << '\n';
}