#include <bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int xx;
    cin >> xx;
    int temp = xx;
    for(int i = 2; i*i <= xx; i++)
        if(xx % i == 0){
            temp = __gcd(temp, i);
            temp = __gcd(temp, xx/i);
        }
    cout << temp << '\n';
}