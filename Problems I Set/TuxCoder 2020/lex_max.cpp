#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        set <int> A;
        for(int i = 0; i < n; i++)
            A.insert(i);
        while(q--){
            int l, r, x;
            cin >> l >> r >> x;
            if(x == 0){
                auto l_pos = A.lower_bound(l-1), r_pos = A.upper_bound(r-1);
                A.erase(l_pos, r_pos);
            }
        }
        for(int i = 0; i < n; i++)
            cout << (A.find(i) != A.end()) << ' ';
        cout << '\n';
    }
    return 0;
}