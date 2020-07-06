#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m;
        int a[n], b[m];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> x;
                if(x){
                    a[i] = 1;
                    b[j] = 1;
                }
            }
        }
        x = 0;y =0;
        for(int i = 0; i < n; i++){
            x += (a[i] == 0);
        }
        for(int i = 0; i < m; i++){
            y += (b[i] == 0);
        }
        bool we = 0;
        if(((x&1) ^ (y&1)) == 1){
            we = min(x, y) & 1;
        }
        else{
            we = x & 1;
        }
        if(we)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
    }
}