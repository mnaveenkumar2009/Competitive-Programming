#include <bits/stdc++.h>

using namespace std;

#define Max 256
short P[10][Max][Max];
short n, m;

short query(short x1, short y1, short x2, short y2) {
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    short i = 0, ans = 0;
    while(x1 < x2 && y1 < y2){
        if((x1 & 1) && (y1 & 1)){
            ans = max(ans, P[i][x1++][y1++]);
        }
        if((x2 & 1) && (y2 & 1)){
            ans = max(ans, P[i][--x2][--y2]);
        }
        i++;
        x1/=2;
        x2/=2;
        y1/=2;
        y2/=2;
    }
    return ans;
}

short update(short x, short y, short value) {
    P[0][x][y] = value;
    // cout << x << ' ' << y << ' ' << value << '\n';
    for(int i = 1; i < 10; i++){
        x >>= 1;
        y >>= 1;
        P[i][x][y] = max(max(P[i-1][x<<1][y<<1], P[i-1][x<<1][(y<<1) | 1]), max(P[i-1][(x<<1)|1][(y<<1)|1], P[i-1][(x<<1)|1][y<<1]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(short i = 0; i < n; i++){
            for(short j = 0; j < m; j++){
                cin >> P[0][i][j];
                update(i, j, P[0][i][j]);
            }
        }
        int q;
        cin >> q;
        while(q--){
            short c;
            cin >> c;
            if(c == 1){
                short x, y, v;
                cin >> x >> y >> v;
                update(x - 1, y - 1, v);
            }
            else{
                short x1, y1, x2, y2;
                cin >> x1 >> x2 >> y1 >> y2;
                cout << query(x1 - 1, y1 - 1, x2, y2) << '\n';
            }
            // for(short i = 0; i < n; i++){
            //     for(short j = 0; j < m; j++){
            //         cout << P[1][i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
        }
    }
    return 0;
}