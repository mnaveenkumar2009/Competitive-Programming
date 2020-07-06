#include<bits/stdc++.h>
using namespace std;
#define int long long

int brute(vector <int> a){
    int ret = 0;
    for(auto i1 = a.begin(); i1 != a.end(); i1++){
        for(auto i2 = i1 + 1; i2 != a.end(); i2++){
            for(auto i3 = i2 + 1; i3 != a.end(); i3++){
                for(auto i4 = i3 + 1; i4 != a.end(); i4++){
                    ret += *i1 * *i2 * *i3 * *i4;
                }
            }
        }   
    }
    return ret;
}

signed main(){
    int n;
    cin >> n;
    vector <int> a(n);
    int total = 0, square_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
        square_sum += a[i] * a[i];
    }
    int ans = total * total * total * total;
    for(int i = 0; i < n; i++){
        ans -= a[i] * a[i] * a[i] * a[i]; // a^4
        ans -= 4 * a[i] * a[i] * a[i] * (total - a[i]); // a^3b
        ans -= 3 * a[i] * a[i] * (square_sum - (a[i] * a[i])); // a^2b^2
        ans -= 6 * a[i] * a[i] * ((total - a[i]) * (total - a[i]) - (square_sum - a[i] * a[i])); //a^2bc
    }
    cout << brute(a) << '\n';
    cout << ans / 24 << '\n';
}