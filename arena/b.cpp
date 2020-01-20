#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    while(cin >> n >> m){
        if(n == 0)break;
        for(int i = 2; i*i <= max(25, n); i++){
            int c = 0;
            while(n % i == 0){
                c++;
                n /= i;
            }
            ans *= 2 * c + 1;
        }
        if(n != 1){
            ans *= 5;
        }
        cout << ans << '\n';
    }
    return 0;
}