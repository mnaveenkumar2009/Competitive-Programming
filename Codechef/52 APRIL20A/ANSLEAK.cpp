#include <bits/stdc++.h>
using namespace std;

signed main(){
    // srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int F[n][m];
        memset(F, 0, sizeof(F));
        int C[k][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                cin >> C[j][i];
                F[i][C[j][i] - 1]++;
            }
        }
        int number_of_iterations = 20001;
        number_of_iterations *= 5000.0/k;
        // cout << number_of_iterations << '\n';
        vector <int> a(n), ans;
        int max_ans = -1;
        for(int i = 0; i < n; i++){
            a[i] = (max_element(F[i], F[i] + m) - F[i]) + 1;
            // cout << a[i] << ' ';
        }
        
        int scor[k];
        for(int i = 0; i < k; i++){
            scor[i] = 0;
            for(int j = 0; j < n; j++){
                scor[i] += a[j] == C[i][j];
            }
        }
        
        while(number_of_iterations--){
            // for(int i = 0; i < n; i++){
            //     cout << a[i] << ' ';
            // }
            // cout << '\n';
            // for(int i = 0; i < k; i++)cout <<scor[i] << ' ';cout << '\n';
            
            int worst_i = min_element(scor, scor + k) - scor, mini = scor[worst_i];
            if(mini > max_ans){
                ans = a;
                max_ans = mini;
            }
            vector <int> ind;
            for(int i = 0; i < n; i++){
                if(a[i] != C[worst_i][i]){
                    ind.push_back(i);
                }
            }
            int j = rand() % ((int)ind.size());
            for(int i = 0; i < k; i++){
                scor[i] -= a[ind[j]] == C[i][ind[j]];
            }
            a[ind[j]] = C[worst_i][ind[j]];
            for(int i = 0; i < k; i++){
                scor[i] += a[ind[j]] == C[i][ind[j]];
            }
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}