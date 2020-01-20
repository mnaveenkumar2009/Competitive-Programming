#include <bits/stdc++.h>
using namespace std;

int main(){
    int k1, k2, k3, x;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3, a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + k1);
    sort(a + k1, a + k1 + k2);
    sort(a + k1 + k2, a + n);
    set <int> X;
    for(int i = 0; i < n; i++){
        if(X.lower_bound(a[i]) != X.end())
            X.erase(X.lower_bound(a[i]));
        X.insert(a[i]);
    }
    cout << (n - X.size()) << '\n';
}