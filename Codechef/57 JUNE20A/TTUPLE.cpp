#include <bits/stdc++.h>
using namespace std;

int a[3], b[3], ans;

bool check(int x, int y){
    if(!y)return 0;
    return ((x % y) == 0);
}

int f(int mask, vector <int> Avail){
    if(mask == 7)
        ans = min(ans, 2);
    for(int i = 0; i < 3; i++){
        if(!((mask >> i)&1)){
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ans = 3;
        cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
        pair <int, int> A[3];
        set <int> S, P;
        for(int i = 0; i < 3; i++){
            A[i].first = a[i];
            A[i].second = b[i];
            if(b[i] != a[i]){
                S.insert(b[i] - a[i]);
                if(!a[i])
                    P.insert(rand());
                else
                    P.insert(b[i]/a[i] - (b[i]%a[i]) * rand());
            }
        }
        ans = min(ans, (int)S.size());
        ans = min(ans, (int)P.size());
        if(ans == 3){
            for(int i = 0; i < 3; i++){
                for(int j = 1; j < 3; j++){
                    if(check(b[j] - b[i], a[j] - a[i])){
                        int k = 3 - (i + j);
                        int d = (b[j] - b[i]) / (a[j] - a[i]);
                        int x = b[i] - a[i] * d;
                        if(a[k] + x == b[k])
                            ans = min(ans, 2);
                        if(a[k] * d + x == b[k])
                            ans = min(ans, 2);
                        if(a[k] * d == b[k])
                            ans = min(ans, 2);
                        if(d){
                            if(x % d == 0){
                                if(a[k] + x/d == b[k])
                                    ans = min(ans, 2);
                            }
                        }
                    }
                }
            }
        }

        if(ans == 3){
            sort(A, A + 3);
            do{
                for(int i = 0; i < 3; i++){
                    a[i] = A[i].first;
                    b[i] = A[i].second;
                }
                // 0 gets d1, 1 gets d2, 2 gets d1 U d2
                for(int msk = 0; msk < 4; msk++){
                    int cur = a[2];
                    if(msk&1)
                        cur += b[0] - a[0];
                    else{
                        if(!check(b[0], a[0]))continue;
                        cur *= b[0]/a[0];
                    }
                    if(msk/2)
                        cur += b[1] - a[1];
                    else{
                        if(!check(b[1], a[1]))continue;
                        cur *= b[1]/a[1];
                    }
                    if(cur == b[2])
                        ans = min(ans, 2);
                }
            }while(next_permutation(A, A + 3));
        }

        cout << ans << "\n";
    }
}