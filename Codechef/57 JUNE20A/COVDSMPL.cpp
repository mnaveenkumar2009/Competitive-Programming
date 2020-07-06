#include <bits/stdc++.h>
using namespace std;

int a[60][60], n, p;

int askit(int r1, int c1, int r2, int c2){
    cout << 1 << ' ' << r1 + 1 << ' ' << c1 + 1 << ' ' << r2 + 1 << ' ' << c2 + 1 << endl;
    int x;  
    cin >> x;
    return x;
}
void quer(int r1, int c1, int r2, int c2, int x){
    if(x == 0){
        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                a[i][j] = 0;
            }
        }
        return;
    }
    if(x == ((r2 - r1 + 1) * (c2 - c1 + 1))){
        for(int i = r1; i <= r2; i++){
            for(int j = c1; j <= c2; j++){
                a[i][j] = 1;
            }
        }
        return;
    }
    int mid = max(r2 - r1, c2 - c1)/2;
    if(max(r2 - r1, c2 - c1) == 0){
        // 1*1
        a[r1][c1] = x;
        return;
    }
    if(r2 - r1 > c2 - c1){
        int x2 = askit(r1, c1, r1 + mid, c2);
        quer(r1, c1, r1 + mid, c2, x2);
        quer(r1 + mid + 1, c1, r2, c2, x-x2);
    }
    else{
        int x2 = askit(r1, c1, r2, c1 + mid);
        quer(r1, c1, r2, c1 + mid, x2);
        quer(r1, c1 + mid + 1, r2, c2, x-x2);
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> p; 
        quer(0, 0, n - 1, n - 1, askit(0,0,n-1,n-1));
        cout << 2 << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        cin >> n;
    }
}