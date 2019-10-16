#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    bool xxx = 0;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]&1){
            if(xxx){
                if(a[i]<0){
                    a[i]--;
                }
            }
            else{
                if(a[i]<0){
                    // a[i]--;
                }
                else{
                    a[i]++;
                }
            }
            xxx^=1;
        }
        cout << a[i]/2 << '\n';
    }
}