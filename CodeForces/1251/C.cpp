#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector <int> sodd, seven;
        for(auto i:s){
            if((i-'0')&1){
                sodd.push_back(i-'0');
            }
            else{
                seven.push_back(i-'0');
            }
        }
        int i = 0, j = 0, n = sodd.size(), m = seven.size();
        while(i < n && j < m){
            if(sodd[i] > seven[j]){
                cout << seven[j++];
            }
            else{
                cout << sodd[i++];
            }
        }
        while(i < n){
            cout << sodd[i++];
        }
        while(j < m){
            cout << seven[j++];
        }
        cout << '\n';
    }
}