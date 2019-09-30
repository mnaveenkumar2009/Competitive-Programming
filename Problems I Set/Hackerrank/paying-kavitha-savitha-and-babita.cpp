#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double
vector <vector <ld> > mul(vector <vector <ld> > &a,vector <vector <ld> > &b){
    vector <vector <ld> > res(4, vector<ld> (4, 0));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]));
    return res;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        N--;
        ld P, Q, R;
        cin >> P >> Q >> R;
        vector <vector <ld> > a(4, vector <ld> (4,0)), res = a;
        vector <ld> ans(4, 0);
        for(int i = 0; i < 4; i++){
            res[i][i] = a[i][3] = 1;
        }
        a[0][0] = a[1][0] = a[2][0] = P;
        a[0][1] = a[1][1] = a[2][1] = Q;
        a[0][2] = a[1][2] = a[2][2] = R;
        a[0][3] -= P;
        a[1][3] -= Q;
        a[2][3] -= R;
        while(N){
            if(N & 1){
                res = mul(res, a);
                N--;
            }
            else{
                a = mul(a, a);
                N >>= 1;
            }
        }
        for(int i = 0; i < 4; i++)
            ans[i] = (1 + res[i][3]);
        cout << fixed << setprecision(7) << (ans[0] * P + ans[1] * Q + ans[2] * R)<< '\n';
    }
    return 0;
}