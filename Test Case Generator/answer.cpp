#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
ld P[3];
void mul(vector <ld> &a, vector <ld> &b){
    ld tem = 0;
    for (int k = 0; k < 3; k++)
        tem += (b[k] * P[k]);
    for (int i = 0; i < 3; i++){
        a[i] += tem;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        N--;
        cin >> P[0] >> P[1] >> P[2];
        if(N==0){
            cout<<"1\n";continue;
        }
        vector <ld> a(3), res(3);
        ld ans = 0;
        a[0] = 1 - P[0];
        a[1] = 1 - P[1];
        a[2] = 1 - P[2];
        res = a;
        N--;
        while(N){
            if(N & 1){
                mul(res, a);
                N--;
            }
            else{
                mul(a, a);
                N >>= 1;
            }
        }
        for(int i = 0; i < 3; i++)
            ans += (1 + res[i])*P[i];
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}