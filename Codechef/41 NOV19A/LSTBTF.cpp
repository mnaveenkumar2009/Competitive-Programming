#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXL 10000000
int F(int x){
    int ret = 0;
    while(x){
        ret = ret + (x%10)*(x%10);
        if(x%10 == 0)
            return -1;
        x/=10;
    }
    return ret;
}
bool issq(int n){
    if(n == -1)return 0;
    int x = sqrt(n);
    return (x*x == n);
}
signed main(){
    vector <int> ans(2000, -1);
    for(int i = MAXL; i > 0; i--){
        if((int)log10(i) == 7 - 1){
            int pre = F(i);
            if((pre!=-1))
                ans[pre] = i;
        }
    }
    int a[7] = {1, 34, 122, 1111, 11123, 111112, 10000000}; // 7 is wrong
    for(int i = 0; i < 2000; i++){
        if(issq(i) && ans[i]!=-1){
            a[6] = min(a[6], ans[i]);
        }
    }
    int T;
    cin >> T;
    while(T--){
        int N;
        N = T + 1;
        cin >> N;

        if(N <= 7)
            cout << a[N - 1] << '\n';
        else{
            int cur = N - 7, anss = 1e9;
            string s(cur, '1'), s2;
            while(anss == 1e9){
                int req = sqrt(N);
                while(req * req - cur < 2000){
                    if(req*req - cur >= 0){
                        if(ans[req*req - cur] != -1)
                            anss = min(anss, ans[req*req - cur]);
                    }
                    req++;
                }
                if(anss == 1e9){
                    cur = cur + 80;
                    s.pop_back();
                    s2.push_back('9');
                }
            }
            // cout << F(anss) + s.length() + s2.length()*9 << '\n';
            cout << s << anss << s2 << '\n';
            // assert(N == (int)(s.length() + log10(ans[req*req - cur]) + 1));
        }
    }
}