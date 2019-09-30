#include <bits/stdc++.h>
using namespace std;
bool uniq(int s){
    vector <int> a(10);
    while(s){
        a[s%10]++;
        s/=10;
    }
    bool ret = 1;
    for(auto i:a){
        if(i>1)
            ret =0;
    }
    return ret;
}
int main(){
    int s, r;
    cin >> s >> r;
    while(s != r + 1){
        if(uniq(s)){

            break;
        }
        s++;
    }
    if(s==r+1)
        s = -1;
    cout << s << '\n';
}