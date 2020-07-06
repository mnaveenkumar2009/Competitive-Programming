#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int f(int i, int j){
    return (abs(i) > abs(j));
}

signed main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, f);
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }
    int ans = 1;
    if((*max_element(a, a + n) <= 0 && (k&1)) || (k == n)){
        reverse(a, a + n);
        for(int i = 0; i < k; i++){
            ans *= a[i];
            ans %= mod;
        }
        cout << ((ans + mod) % mod) << '\n';
    }
    else{
        bool x = 0;
        for(int i = 0; i < k; i++){
            x ^= (a[i] < 0);
            if(a[i] == 0){
                cout << "0";
                return 0;
            }
            
        }
        int pos_pos = -1, pos_neg = -1;
        int rep_pos = -1, rep_neg = -1;
        for(int i = 0; i < k; i++){
            if(a[i] >= 0)
                pos_pos = i;
            else
                pos_neg = i;
        }
        for(int i = k; i < n; i++){
            if(a[i] >= 0){
                rep_pos = i;
                break;
            }
        }
        for(int i = k; i < n; i++){
            if(a[i] <= 0){
                rep_neg = i;
                break;
            }
        }
        // cout << pos_pos << ' ' << pos_neg << ' ' << rep_pos <<' ' << rep_neg << '\n';
        if(x){
            bool should_take_pos = 0;
            if(pos_pos == -1 || rep_neg == -1){
                should_take_pos = 0;
            }
            else{
                if(pos_neg == -1 || rep_pos == -1){
                    should_take_pos = 1;
                }
                else{
                    if(-(a[rep_neg] * a[pos_neg]) > -(a[rep_pos] * a[pos_pos])){
                        should_take_pos = 0;
                    }
                    else{
                        should_take_pos = 1;
                    }
                }
            }
            if(should_take_pos){
                swap(a[rep_neg], a[pos_pos]);
            }
            else{
                swap(a[rep_pos], a[pos_neg]);
            }
        }
        for(int i = 0; i < k; i++){
            ans *= a[i];
            ans %= mod;
        }
        cout << ((ans + mod) % mod) << '\n';
        
    }
    
}