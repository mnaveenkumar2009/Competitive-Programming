#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            vector < vector <int> > ans(n, vector <int> (n, 0));
            for(int i = 0; i < n; i++){
                int xxx = n/2;
                for(int j = i + 1; xxx-- ; j++){
                    ans[i][j%n] = 1;
                }
            }
            cout <<"YES\n";
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    cout << ans[i][j];
                }cout << '\n';
            }
        }
        else{
            cout <<"NO\n";
        }
    }
}