#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        vector <int> p;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] != i + 1){
                p.push_back(i);
            }
        }
        if(p.size() == 0){
            cout << "0\n";
        }
        else{
            if(p[p.size() - 1] - p[0] == p.size() - 1){
                cout << "1\n";
            }
            else{
                cout << "2\n";
            }
        }
    }
}