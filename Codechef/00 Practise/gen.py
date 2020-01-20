#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2e5, m = n;
    string s, t;
    for(int i = 0; i < n; i++)
        s.push_back('1');
    for(int i = 0; i < n; i++)
        t.push_back('6');
    cout << n << ' ' << m << '\n';
    cout << s << '\n' << t << '\n';
    for(int i = 0; i < 10; i++)
        cout << 1000 << ' ';
    cout << '\n';
    for(int i = 0; i < 10; i++)
        cout << 1000 << ' ';
    cout << '\n';
}