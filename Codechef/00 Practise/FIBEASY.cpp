#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int t;
    cin >> t;
    while(t--){
        int n, x = 0;
        cin >> n;
        while(n = n/2)
            x++;
        n = (1LL << x) - 1;
        vector <int> a(2, 0);
        a[1] = 1;
        while(a.size() < 100)
            a.push_back((a[a.size()-1]+a[a.size()-2])%10);
        cout << a[n % 60] << '\n';
    }
}