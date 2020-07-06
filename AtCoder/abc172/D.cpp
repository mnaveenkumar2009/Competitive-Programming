#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans = 0, n;
    cin >> n;
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j*i <= n; j++)
            ans += i*j;
    cout << ans << '\n';
}