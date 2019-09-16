#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    long long n, k, i = -1, j;
    unordered_map <int, int> N;
    cin >> n >> k;
    while(cin >> n)
        N[n]++;
    long long Ds = N.size(), sum[Ds] = {0};
    for(auto map_x : N)
        for(j = n = 0, i++; j < Ds; j++)
            sum[j] = (++n * map_x.second + (n = i ? sum[j] : 0)) % mod ;
    cout << ++sum[min(k, Ds) - 1] % mod;
}