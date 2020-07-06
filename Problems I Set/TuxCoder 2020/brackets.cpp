#include <bits/stdc++.h>
using namespace std;

string s;

int grundy(int l, int r){
    int res = 0, c = 0, lef = l;
    for(int i = l; i <= r; i++){
        c += (s[i] == '(') - (s[i] == ')');
        if(c == 0){
            res ^= (grundy(lef + 1, i - 1) + 1);
            lef = i + 1;
        }
    }
    return res;
}
int main(){
    cin >> s;
    while(cin >> s){
        if(grundy(0, s.size() - 1))
            cout << "First\n";
        else
            cout << "Second\n";
    }
}