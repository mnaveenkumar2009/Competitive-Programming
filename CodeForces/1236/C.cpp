#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int X = 1;
    int a[n][n];
    bool xxx = 0;
    for(int i = 0; i < n; i++){
        if(xxx)
            for(int j = 0; j < n; j++){
                a[i][j] = X++;
            }
        else{
            for(int j = n-1; j >= 0; j--){
                a[i][j] = X++;
            }
        }
        xxx^=1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[j][i] << ' ';
        }
        cout << '\n';
    }
}