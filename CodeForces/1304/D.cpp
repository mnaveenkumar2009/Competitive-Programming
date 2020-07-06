#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++){
            a[i] = i + 1;
            b[i] = n - i;
        }
        int c = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == '>')
                c++;
            else{
                reverse(a.begin() + i - c, a.begin() + i + 1);
                c = 0;
            }
        }
        reverse(a.begin() + n - 1 - c, a.begin() + n);
        c = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == '<')
                c++;
            else{
                reverse(b.begin() + i - c, b.begin() + i + 1);
                c = 0;
            }
        }
        reverse(b.begin() + n - 1 - c, b.begin() + n);
        swap(a, b);
        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << '\n';
        for(int i = 0; i < n; i++)
            cout << b[i] << ' ';
        cout << '\n';
    }
}