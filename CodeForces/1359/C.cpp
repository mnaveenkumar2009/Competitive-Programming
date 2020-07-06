#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double 

int x, y;
ld h;

ld f(int X){
    ld tem = (X - 1) * y + (X) * x;
    tem /= (ld) (2*X - 1);
    return tem;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> h;
        if((int)h * 2 > x + y){
            int high = 1e9 + 1, low = 1;
            while(high - low >= 5){
                int mid1 = low + (high - low)/3;
                int mid2 = low + ((high - low) * 2)/3;
                ld x1 = abs(f(mid1) - h) , x2 = abs(f(mid2) - h);
                if(x1 > x2){
                    low = mid1;
                }
                if(x2 > x1){
                    high = mid2;
                }
                if(x2 == x1){
                    low = mid1;
                    high = mid2;
                }
            }
            int pans = low;
            ld ans = 1e18;
            for(int ind = low; ind <= high; ind++){
                if(ans > abs(f(ind) - h)){
                    ans = abs(f(ind) - h);
                    pans = ind;
                }
            }
            cout << (pans) * 2 - 1 << '\n';
        }
        else{
            cout << "2\n";
        }
    }
}