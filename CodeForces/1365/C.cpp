#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    {
        int n;
        cin >> n;
        int a[2*n], b[2*n], c[2*n], p[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            p[a[i] - 1] = i;
        }
        int C[5*n];
        memset(C, 0, sizeof(C));
        for(int i = 0; i < n; i++){
            cin >> b[i];
            C[((p[b[i] - 1] - i) % n + n)%n]++;
        }
        cout << *max_element(C, C + 5*n) << '\n';
    }   
}