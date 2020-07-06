#include <bits/stdc++.h>
using namespace std;
 
#define int long long
int done[1000006];
int N;
int query(int i){
    if(done[N - i] != -1){
        return done[N - i];
    }
    int x;
    cout << "? " << N - i << endl;
    cin >> x;
    if(x != i){
        // none of it's divisors are possible
        for(int j = 1; j <= N; j++){
            if(i % j == 0)
                done[N - j] = 0;
        }
    }
    return done[N - i] = x;
}
signed main(){
    int t;
    cin >> t;
    bool isp[1000006];
    for(int i = 0; i < 1e6 + 6; i++){
        isp[i] = 1;
    }
    isp[0] = 0;
    for(int i = 2; i < 1e6 + 6; i++){
        if(isp[i]){
            for(int j = 2; j * i < 1e6 + 6; j++){
                isp[i*j] = 0;
            }
        }
    }
    while(t--){
        memset(done, -1, sizeof(done));

        int n, q;
        cin >> n >> q;
        if(n == 1){
            cout << "! 1" << endl;
            cin >> n;
            continue;
        }
        N = n;
        if(n % 1024 == 0){
            n/=1024;
            // int x = query(n/1024);
            // if(x == n/1024){
            //     n /= 1024;
            //     break;
            // }
        }
        if(n % 64 == 0){
            // cout << n/64 << '\n';
            int x = query(n/64);
            if(x == n/64){
                n /= 64;
                break;
            }
        }
        if(n % 64 == 0){
            // cout << n/64 << '\n';
            int x = query(n/64);
            if(x == n/64){
                n /= 64;
                break;
            }
        }
        if(n % 64 == 0){
            // cout << n/64 << '\n';
            int x = query(n/64);
            if(x == n/64){
                n /= 64;
                break;
            }
        }
        if(n % 32 == 0){
            // cout << n/64 << '\n';
            int x = query(n/32);
            if(x == n/32){
                n /= 32;
                break;
            }
        }
        if(n % 729 == 0){
            int x = query(n/729);
            if(x == n/729){
                n /= 729;
                break;
            }
        }
        if(n % 729 == 0){
            int x = query(n/729);
            if(x == n/729){
                n /= 729;
                break;
            }
        }
        if(n % 27 == 0){
            int x = query(n/27);
            if(x == n/27){
                n /= 27;
                break;
            }
        }
        while(1){
            if(n == 1)break;
            int i;
            for(i = 2; i <= n; i++){
                if(n % i == 0){
                    if(!isp[i])continue;
                    int x = query(n/i);
                    if(x == n/i){
                        n /= i;
                        break;
                    }
                }
            }
            if(i == n + 1){
                break;
            }
        }
        cout << "! " << N/n << endl;
        cin >> n;
    }

}