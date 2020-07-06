#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;

#define upperlimit 100000

struct library {
    int id;
    int n;
    int t;
    int m;
    int sc;
    int w;
    vector<int> bookid;
};

const int L = 1e4;
const int W = 1e5;

int s[upperlimit];
library libs[upperlimit];
int dp[L+2][W+2];

int main()
{
	memset(dp, 0, sizeof(dp));
    // Your code here
    int b, l, d;
    cin >> b >> l >> d;
    for(int i = 0; i < b; ++i) cin >> s[i];

    // Libraries
    for(int i = 0; i < l; ++i) {
        libs[i].id = i;
        libs[i].sc = 0;
        cin >> libs[i].n >> libs[i].t >> libs[i].m;
        libs[i].w = libs[i].t + 1;
        for(int j = 0; j < libs[i].n; ++j) {
            int r1;
            cin >> r1;
            libs[i].bookid.push_back(r1);
            libs[i].sc += s[r1];
        }
    }

    vi taken(L+2);

    for(int w=0; w<W; w++) {
        dp[0][w] = libs[0].w <= w ? libs[0].sc : 0;
    }
    for(int i=1; i<l; i++) {
        for(int w=0; w <= W; w++) {
            if(w < libs[i].w) {
                dp[i][w] = dp[i-1][w];
            }
            else {
                dp[i][w] = max(libs[i].sc + dp[i-1][w-libs[i].w], dp[i-1][w]);
            }
        }
    }

    int curw = W;
	int res = dp[L-1][W];
	// cout << res << '\n';
    int i=L;
    while(i>=0 and curw >0) {
		
        if(dp[i-1][curw] != res) {
            taken[i] = 1;
            curw -= libs[i].w;
			res -= libs[i].sc;
        }
        else {
            taken[i] = 0;
        }
        i--;
    }
	
	// for(int i = 0; i < L + 2; i++){
	// 	for(int j = 0; j < W + 2; j++){
	// 		dp[i][j];
	// 	}
	// }
	// cout << dp[L-1][W-1] << '\n';;
    vi order;
    for(int i=0; i<l; i++) {
        if(taken[i]){ 
			// cout << i << '\n';
			order.push_back(i);}
    }
    // for(int i=0; i<l; i++) {
    //     if(!taken[i]) {
    //         order.push_back(i);
    //     }
    // }
	l = order.size();
   // output
    cout << l << "\n";
    for(int i = 0; i < l; ++i) {
        int jj=order[i];
        cout << libs[jj].id << " " << libs[jj].n << "\n";
        for(int j = 0; j < libs[jj].n; ++j) {
            cout << libs[jj].bookid[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}