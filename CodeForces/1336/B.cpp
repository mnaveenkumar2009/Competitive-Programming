#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int x, int y, int z){
    // cout << x << ' ' << y << ' ' << z << '\n';
    int a = x - y;
    int b = y - z;
    int c = z - x;
    return a * a + b * b + c * c;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int a[n1], b[n2], c[n3];
        for(int i = 0; i < n1; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n2; i++){
            cin >> b[i];
        }
        for(int i = 0; i < n3; i++){
            cin >> c[i];
        }
        sort(a, a + n1);
        sort(b, b + n2);
        sort(c, c + n3);
        int ans = 3e18;
        // cout << ans << '\n';
        for(int i = 0; i < n1; i++){
            int x = a[i];
            int p = upper_bound(b, b + n2, x) - b;
            int pc = upper_bound(c, c + n3, x) - c;
            for(int j = p - 2; j <= p + 2; j++){
                if(j >=0 && j < n2){
                    for(int k = pc - 2; k <= pc + 2; k++){
                        if(k >=0 && k < n3){
                            ans = min(ans, f(x, b[j], c[k]));
                        }
                    }
                    
                }
            }
        }
        for(int i = 0; i < n2; i++){
            int x = b[i];
            int p = upper_bound(a, a + n1, x) - a;
            int pc = upper_bound(c, c + n3, x) - c;
            for(int j = p - 2; j <= p + 2; j++){
                if(j >=0 && j < n1){
                    for(int k = pc - 2; k <= pc + 2; k++){
                        if(k >=0 && k < n3){
                            ans = min(ans, f(x, a[j], c[k]));
                        }
                    }
                    
                }
            }
        }
        for(int i = 0; i < n3; i++){
            int x = c[i];
            int p = upper_bound(b, b + n2, x) - b;
            int pc = upper_bound(a, a + n1, x) - a;
            for(int j = p - 2; j <= p + 2; j++){
                if(j >=0 && j < n2){
                    for(int k = pc - 2; k <= pc + 2; k++){
                        if(k >=0 && k < n1){
                            ans = min(ans, f(x, b[j], a[k]));
                        }
                    }
                    
                }
            }
        }
        
        cout << ans << '\n';
    }
}