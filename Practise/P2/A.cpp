#include <bits/stdc++.h>
using namespace std;

int main(){
    #define int long long
    int a, b, c, x;
    cin >> a >> b >> c;
    x = (a*b)/__gcd(a, b);
    x = (x*c)/__gcd(x, c);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << a + b + c << '\n';
    for(int i = 0; i < a+b+c; i++){
        if(i < a){
            int num = i;
            cout << x/a << ' ';
            cout << num % a + 1 << ' ' << num % b + 1 << ' ' << num % c + 1 << '\n';
        }
        else{
            if(i<a+b){
                int num = i - (a);
                cout << x/b << ' ';
                cout << num % a + 1 << ' ' << num % b + 1 << ' ' << num % c + 1 << '\n';
            }
            else{
                if(i<a+b+c){
                    int num = i - (a+b);
                    cout << x/c << ' ';
                    cout << num % a + 1 << ' ' << num % b + 1 << ' ' << num % c + 1 << '\n';
                }
            }
        }
    }
    
}