#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x1, x2, y1, y2, n, m;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        // y1 < y2
        if(x1 == x2){
            cout << "Draw\n";
            continue;
        }
        if(m == 2){
            if(abs(x1 - x2) <= 2){
                // = 2, knight promotion, = 1 captures in 1 move
                cout << "Aunty\n";
            }
            else
                cout << "Draw\n";
        }
        else{
            // only queen promotions
            if(abs(x1 - x2) == 1){
                // captures on the way to queening
                if(abs(y1 - y2) & 1)
                    cout << "Aunty\n";
                else
                    cout << "Bunty\n";
            }
            else{
                int t1 = m - y1, t2 = y2 - 1;
                bool dir_attack = (abs(x1 - x2) == m - 1);
                if(t1 == t2){
                    if(dir_attack){
                        cout << "Aunty\n";
                    }
                    else
                        cout << "Draw\n";
                }
                else{
                    if(t1 == t2 + 1){
                        if(dir_attack){
                            cout << "Bunty\n";
                        }
                        else
                            cout << "Draw\n";
                    }
                    else{
                        if(t1 < t2)
                            cout << "Aunty\n";
                        else
                            cout << "Bunty\n";
                    }
                }
            }
        }
    }
}