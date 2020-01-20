#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector <int> prin;
        bool we = 1;
        int noi = 60;
        while(noi --){
            for(int i = 0; i < n; i++){
                if(s[i] != t[i]){
                    int j;
                    for(j = i+1; j!=i; j = (j+1)%n){
                        if(t[j] == t[i] && t[j] != s[j]){
                            swap(t[j], s[i]);
                            prin.push_back(i);
                            prin.push_back(j);
                            break;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                if(s[i] != t[i]){
                    int j;
                    for(j = i+1; j!=i; j = (j+1)%n){
                        if(t[j] == t[i] && t[j] != s[j]){
                            swap(t[j], s[i]);
                            prin.push_back(i);
                            prin.push_back(j);
                            break;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++)
                if(s[i]!=t[i]){
                    swap(t[i], s[i]);
                    prin.push_back(i);
                    prin.push_back(i);                
                    break;
                }
        }
        if(s == t){
            cout << "Yes\n";
            int n = prin.size();
            cout << n/2 << '\n';
            for(int i = 0; i < n/2; i++){
                cout << prin[2*i] + 1 << ' ' << prin[2*i+1] + 1 << '\n';
            }
        }
        else{
            cout << "No\n";
        }
    }
}