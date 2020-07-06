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
        int n;
        cin >> n;
        int b[n];
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        if(n == 1){
            if(b[0] > 0){
                cout << "YES\n";
                cout << b[0] << '\n';
            }
            else{
                cout << "NO\n";
            }
            continue;
        }
        sort(b, b + n);
        int fpos = -1;
        for(int i = 1; i < n; i++){
            if(b[i] > 0){
                fpos = i;
                break;
            }
        }
        if(fpos == -1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << b[fpos] << ' ';
            vector <int> C;
            for(int i = 0; i < n; i++){
                if(i != fpos){
                    C.push_back(b[i]);
                }
            }
            for(int i = 1; i < C.size()-1; i += 2){
                swap(C[i], C[i+1]);
            }
            for(auto i:C)cout << i << ' ';
            cout << '\n';
        }
    }
}