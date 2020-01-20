#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, k;
    cin >> n >> k;
    vector <bool> isitxpowk(1e6, 0);
    for(int i = 0; i <= 1e5+10; i++){
        bool we = 1;
        int mult = 1;
        int c = k;
        while(c--){
            mult *= i;
            if(mult > 1e5){
                we = 0;
                break;
            }
        }
        if(!we){
            break;
        }
        isitxpowk[mult] = 1;
    }
    // for(int i = 0; i < 1e5; i++){
    //     if(isitxpowk[i]){
    //         cout << i << '\n';
    //     }
    // }
    // cout << '\n';
    int ans = 0;
    vector <int> a(n), b(1e6, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int temp = a[i];
        int s_e = 1;
        for(int j = 2; j * j <= a[i]; j++){
            if(a[i]%j == 0){
                int c = 0;
                while(a[i]%j==0){
                    c++;
                    a[i]/=j;
                }
                c%=k;
                if(c){
                    // cout<<"ASF " << i << ' ' << c << '\n';
                    bool we = 1;
                    int mult = 1;
                    c = k-c;
                    while(c--){
                        mult *= j;
                        if(mult * s_e > 1e5){
                            we = 0;
                            break;
                        }
                    }
                    if(we)
                        s_e = s_e * mult;
                    else{
                        s_e = -1;
                        break;
                    }
                }
            }
        }
        if(a[i]!=1){
            bool we = 1;
            int mult = 1;
            int c = k-1;
            while(c--){
                mult *= a[i];
                if(mult * s_e > 1e5){
                    we = 0;
                    break;
                }
            }
            if(we)
                s_e = s_e * mult;
            else{
                s_e = -1;
            }
        }
        if(s_e != -1)
            ans += b[s_e];
        for(int j = 1; j * j <= temp; j++){
            if(temp%j==0){
                if(j*j!=temp){
                    if(isitxpowk[temp/j])
                        b[j]++;
                    if(isitxpowk[j])
                        b[temp/j]++;
                }
                else{
                    if(isitxpowk[j])
                        b[j]++;
                }
            }
        }
        // cout << s_e << ' ' << ans << '\n';
    }
    cout << ans << '\n';
}