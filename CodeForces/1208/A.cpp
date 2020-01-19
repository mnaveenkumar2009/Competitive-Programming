#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(c%3 == 0)
            cout << a << '\n';
        if(c%3 == 1)
            cout<<b<<'\n';
        if(c%3==2)
            cout<<(a^b)<<'\n';
    }
	return 0;
}