#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    set <int> P;
    P.insert(0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i)
            if(a[i]%a[i-1])
                P.insert(i);
    }

    while(q--){
        // for(auto i:P)cout <<i <<' ';cout << '\n';
        int x;
        cin >> x;
        if(x==1){
            int pos, val;
            cin >> pos >> val;
            pos--;
            a[pos] = val;
            if(pos){
                if(a[pos]%a[pos-1]){
                    P.insert(pos);
                }
                else{
                    if(P.find(pos)!=P.end())
                        P.erase(pos);
                }
            }
            if(pos != n-1){
                if(a[pos+1]%a[pos]){
                    P.insert(pos+1);
                }
                else{
                    if(P.find(pos+1)!=P.end())
                        P.erase(pos+1);
                }
            }
        }
        else{
            int X;
            cin >> X;
            X--;
            auto posi = P.lower_bound(X);
            if(posi == P.end())
                posi--;
            if(*posi > X)
                posi--;
            cout << *posi + 1 << '\n';
        }
    }
}