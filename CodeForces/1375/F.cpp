#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	pair <int, int> a[3];
	int y;
	cin >> a[0].first >> a[1].first >> a[2].first;
	for(int i = 0; i < 3; i++)
		a[i].second = i + 1;
    sort(a, a + 3);

	cout << "First" << endl;
    cout << 2 * a[2].first - a[1].first - a[0].first << endl;
    cin >> y;
    if(y == a[2].second){
        a[2].first += 2 * a[2].first - a[1].first - a[0].first;
        cout << 2 * a[2].first - a[1].first - a[0].first << endl;
        cin >> y;
    }
    if(y == a[0].second)
        cout << a[2].first - a[1].first << endl;
    else
        cout << a[2].first - a[0].first << endl;
}