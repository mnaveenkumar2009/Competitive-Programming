#include <bits/stdc++.h>
using namespace std;

bool check(int x, int a1, int a2, int a3, int a4){
    return (x != a1 && x != a2 && x != a3 && x != a4 && x != 0);
}
pair <int, int> Best[81][81][6];


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    int n = N;
    int a[N][N];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vector <pair <int, int> > A;
            for(int k = 1; k < n; k++){
                if(k != i && k != j)
                    A.push_back({a[i][k] + a[k][j], k});
            }
            sort(A.begin(), A.end());
            for(int k = 0; k < 6; k++){
                Best[i][j][k] = {0, 0};
            }
            for(int k = 0; k < min((int)(A.size()), 6); k++){
                Best[i][j][k] = A[k];
            }
        }
    }

    if(K == 2){
        cout << Best[0][0][0].first << '\n';
    }
    int ans = 1e9;
    if(K == 4){
        for(int a1 = 0; a1 < n; a1++){
            int a4 = 0, a3 = 0, a2 = 0;
            set <int> X;
            X.insert(0);
            X.insert(a1);
            if(X.size() == n)continue;
            int cur_ans = 0;
            for(int i = 0; i < 6; i++){
                if(check(Best[0][a1][i].second, a1, a2, a3, a4)){
                    cur_ans += Best[0][a1][i].first;
                    break;
                }                        
            }
            for(int i = 0; i < 6; i++){
                if(check(Best[a1][0][i].second, a1, a2, a3, a4)){
                    cur_ans += Best[a1][0][i].first;
                    break;
                }
            }
            ans = min(ans, cur_ans);
        }
        cout << ans << '\n';
    }
    if(K == 6){
        for(int a1 = 0; a1 < n; a1++){
            for(int a2 = 0; a2 < n; a2++){
                int a4 = 0, a3 = 0;
                set <int> X;
                X.insert(0);
                X.insert(a1);
                X.insert(a2);
                if(X.size() == n)continue;
                int cur_ans = 0;
                for(int i = 0; i < 6; i++){
                    if(check(Best[0][a1][i].second, a1, a2, a3, a4)){
                        cur_ans += Best[0][a1][i].first;
                        break;
                    }                        }
                for(int i = 0; i < 6; i++){
                    if(check(Best[a1][a2][i].second, a1, a2, a3, a4)){
                        cur_ans += Best[a1][a2][i].first;
                        break;
                    }
                }

                for(int i = 0; i < 6; i++){
                    if(check(Best[a2][0][i].second, a1, a2, a3, a4)){
                        cur_ans += Best[a2][0][i].first;
                        break;
                    }
                }
                ans = min(ans, cur_ans);
            }
        }
        cout << ans << '\n';
    }
    if(K == 8){
        for(int a1 = 0; a1 < n; a1++){
            for(int a2 = 0; a2 < n; a2++){
                for(int a3 = 0; a3 < n; a3++){
                    int a4 = 0;
                    set <int> X;
                    X.insert(0);
                    X.insert(a1);
                    X.insert(a3);
                    X.insert(a2);
                    if(X.size() == n)continue;
                    int cur_ans = 0;
                    for(int i = 0; i < 6; i++){
                        if(check(Best[0][a1][i].second, a1, a2, a3, a4)){
                            cur_ans += Best[0][a1][i].first;
                            break;
                        }                        }
                    for(int i = 0; i < 6; i++){
                        if(check(Best[a1][a2][i].second, a1, a2, a3, a4)){
                            cur_ans += Best[a1][a2][i].first;
                            break;
                        }
                    }

                    for(int i = 0; i < 6; i++){
                        if(check(Best[a2][a3][i].second, a1, a2, a3, a4)){
                            cur_ans += Best[a2][a3][i].first;
                            break;
                        }
                    }

                    for(int i = 0; i < 6; i++){
                        if(check(Best[a3][0][i].second, a1, a2, a3, a4)){
                            cur_ans += Best[a3][0][i].first;
                            break;
                        }
                    }
                    ans = min(ans, cur_ans);
                }
            }
        }
        cout << ans << '\n';

    }
    if(K == 10){
        for(int a1 = 0; a1 < n; a1++){
            for(int a2 = 0; a2 < n; a2++){
                for(int a3 = 0; a3 < n; a3++){
                    for(int a4 = 0; a4 < n; a4++){
                        int cur_ans = 1e9;
                        for(int i = 0; i < 4; i++){
                            if(check(Best[0][a1][i].second, a1, a2, a3, a4)){
                                cur_ans = Best[0][a1][i].first;
                                break;
                            }                        
                        }
                        for(int i = 0; i < 4; i++){
                            if(check(Best[a1][a2][i].second, a1, a2, a3, a4)){
                                cur_ans += Best[a1][a2][i].first;
                                break;
                            }
                        }

                        for(int i = 0; i < 4; i++){
                            if(check(Best[a2][a3][i].second, a1, a2, a3, a4)){
                                cur_ans += Best[a2][a3][i].first;
                                break;
                            }
                        }

                        for(int i = 0; i < 4; i++){
                            if(check(Best[a3][a4][i].second, a1, a2, a3, a4)){
                                cur_ans += Best[a3][a4][i].first;
                                break;
                            }
                        }
                        for(int i = 0; i < 6; i++){
                            if(check(Best[a4][0][i].second, a1, a2, a3, a4)){
                                cur_ans += Best[a4][0][i].first;
                                break;
                            }
                        }
                        ans = min(ans, cur_ans);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}