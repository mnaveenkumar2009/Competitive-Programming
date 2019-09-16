#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, N = 1000001, ele;
    cin >> n;
    vector <long long> D(N, 0), F(N, 0);
    unordered_map <int, long long> b;
    while(n--){
        cin >> ele;
        unordered_map <int, long long> c;
        for(auto G : b)
            c[__gcd(G.first, ele)] += G.second;
        c[ele] += 1;
        b = c;
        for(auto G : b)
            D[G.first*(G.first < N)] += G.second;
    }
    for(int i = 1; i < N; i++)
        for(int j = 1; j * i < N; j++)
            F[i*j] += D[i];
    cin>>n;
    while(cin>>n)
        cout << F[n] <<'\n';
}