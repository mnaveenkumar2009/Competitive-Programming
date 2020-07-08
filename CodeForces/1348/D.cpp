#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        //  n = t + 1;
        //  if(n == 1)break;
        if(n == 2){
            cout << "1\n0\n";
            continue;
        }
        if(n == 3){
            cout << "1\n1\n";
            continue;
        }
        int k = 0;
        while((1<<k) <= n)
            k++;
        k--;
        cout << k << '\n';// at least 2
        for(int i = 0; i < k - 2; i++){
            cout << (1 << i) << ' ';
        }
        int X = (1 << (k - 1)) - 1;
        int Y = n - X;
        // cout << Y << '\n';
        int F1 = (1 << (k - 2));
        if(Y - F1 <= 2 * F1){
            cout << "0 " << Y - 2*F1 << '\n';
            continue;
        }
        if( Y % 3 == 0){
            int K = Y/3;
            cout << K - F1  << ' ' << K << '\n';
        }
        if(Y % 3 == 1){
            int K = (Y + 2)/3;
            cout << K - F1 << ' ' << K - 2 << '\n';
        }
        if( Y % 3 == 2){
            int K = (Y + 1)/3;
            cout << K -F1 << ' ' << K - 1 << '\n';
        }
    }
}