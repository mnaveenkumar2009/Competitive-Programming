#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, S;
    cin >> t >> S;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        unordered_map <int, int> M;
        bool we = 1;
        for(int i = 0; i < n; i++){
            if(i){
                if(!M[a[i]])
                    we = 0;
            }
            M[a[i]] = 1;
            M[b[i]] = 1;
            if(b[i] <= a[i])
                we = 0;
        }
        if(we)
            cout << "YES\n";
        else{
            if(S == 1)
                cout << "NO\n";
            else{
                if(n == 1){
                    if(b[0] > a[0])
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                    continue;
                }
                unordered_map<int, int> X;
                for(int i = 0; i < n; i++){
                    X[a[i]]++;
                    X[b[i]]++;
                }
                int sum = 0, maxi = 0, mp = 0;
                for(auto i:X){
                    if(i.second){
                        sum += i.second;
                        if(maxi < i.second){
                            maxi = i.second;
                            mp = i.first;
                        }
                    }
                }
                we = 1;
                if(a[0] > mp){
                    X[a[0]]--;
                    for(int i = 0; i < n; i++){
                        if(a[i] != a[0]){
                            X[a[i]]--;
                            break;
                        }
                        if(b[i] != b[0]){
                            X[b[i]]--;
                            break;
                        }
                    }
                    sum = 0, maxi = 0, mp = 0;
                    for(auto i:X){
                        if(i.second){
                            sum += i.second;
                            if(maxi < i.second){
                                maxi = max(maxi, i.second);
                                mp = i.first;
                            }
                        }
                    }
                }
                if(a[0] == a[n - 1]){
                    if(b[n-1] <= a[0]){
                        we = 0;
                    }
                }
                // assert(n != 2);
                if(n == 2 && (a[0] >= b[1] || b[0] >= a[1])){
                    we = 0;
                }
                // cout << maxi << ' ' << sum << '\n';
                if(maxi * 2 <= sum && we)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
}